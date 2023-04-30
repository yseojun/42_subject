/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:24:55 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/20 22:04:22 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "f_string.h"
#include "util.h"
#include <stdlib.h>
#include <fcntl.h>
#include <sys/errno.h>

void	print_all(char *output, long long *addr, int len, int is_c)
{
	if (!(len > 16 && !ft_strncmp(output + len - 32, output + len - 16, 16)
			&& !ft_strncmp(output + len - 16, output + len, 16)))
	{
		if (len != 0 && !ft_strncmp(output + len - 16, output + len, 16))
			write(1, "*\n", 2);
		else
		{
			print_addr(*addr, is_c);
			print_ascii(output + len, 16, is_c);
			if (is_c)
				print_content(output + len, 16);
		}
	}
}

char	*print_hexdump(char *output, long long *addr, int is_c)
{
	int		len;
	int		idx;
	char	*remain;
	int		size;

	len = 0;
	size = ft_strlen(output);
	remain = (char *)malloc(sizeof(char) * 17);
	while (len + 16 <= size)
	{
		print_all(output, addr, len, is_c);
		len += 16;
		*addr += 16;
	}
	idx = 0;
	while (len < size)
		remain[idx++] = output[len++];
	remain[idx] = '\0';
	return (remain);
}

char	*hexdump_file(char **av, int n, char **remain, long long *addr)
{
	char	*output;
	int		fd;
	int		is_c;

	is_c = is_c_option(av[1]);
	fd = open(av[n], O_RDWR);
	if (fd < 0 && errno == EISDIR)
	{
		hexdump_errno(av, n);
		return (0);
	}
	close(fd);
	fd = open(av[n], O_RDONLY);
	if (fd < 0)
		hexdump_errno(av, n);
	else
	{
		output = read_content(remain, fd);
		close(fd);
		*remain = print_hexdump(output, addr, is_c);
		free(output);
	}
	return (*remain);
}

char	*hexdump_input(long long *addr, int is_c)
{
	char	*output;
	char	*remain;

	output = read_content(&remain, 0);
	remain = print_hexdump(output, addr, is_c);
	return (remain);
}

int	main(int ac, char **av)
{
	int			n;
	long long	addr;
	char		*remain;

	n = 1;
	remain = 0;
	addr = 0;
	if (ac == 1)
		remain = hexdump_input(&addr, 0);
	else if (ac == 2 && is_c_option(av[1]))
		remain = hexdump_input(&addr, is_c_option(av[1]));
	else if (ac >= 2)
	{
		if (is_c_option(av[1]))
			n++;
		while (n < ac)
		{
			remain = hexdump_file(av, n, &remain, &addr);
			n++;
		}
	}
	final(remain, addr, av, ac);
	return (0);
}
