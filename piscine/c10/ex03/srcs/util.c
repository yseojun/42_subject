/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:40:45 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/20 21:50:30 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "f_string.h"

char	*read_content(char **remain, int fd)
{
	char	*new;
	char	*buf;
	int		rbyte;

	buf = (char *)malloc(sizeof(char) * 4001);
	buf[4000] = '\0';
	new = (char *)malloc(sizeof(char));
	new[0] = '\0';
	if (*remain)
		new = ft_newstr(*remain, new);
	rbyte = read(fd, buf, 4000);
	buf[rbyte] = '\0';
	while (rbyte)
	{
		buf[rbyte] = '\0';
		new = ft_newstr(new, buf);
		buf = (char *)malloc(sizeof(char) * 4001);
		buf[4000] = '\0';
		rbyte = read(fd, buf, 4000);
	}
	free(buf);
	return (new);
}

int	is_c_option(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	if (n != 2)
		return (0);
	if (str[0] == '-' && str[1] == 'C')
		return (1);
	return (0);
}

void	hexdump_errno(char **av, int n)
{
	write(1, basename(av[0]), ft_strlen(basename(av[0])));
	write(1, ": ", 2);
	write(1, av[n], ft_strlen(av[n]));
	write(1, ": ", 2);
	write(1, strerror(errno), ft_strlen(strerror(errno)));
	write(1, "\n", 1);
}

void	print_final_addr(long long addr, int is_c)
{
	int		n;
	char	*hex;
	char	output[8];

	hex = "0123456789abcdef";
	n = 0;
	while (n < 8)
	{
		output[7 - n] = hex[addr % 16];
		addr /= 16;
		n++;
	}
	if (!is_c)
		write(1, output + 1, 7);
	else
		write(1, output, 8);
}
