/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:23:46 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/20 14:43:55 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/errno.h>
#include <string.h>
#include <libgen.h>

int		ft_strlen(char *str);
void	tail_offset_error(char **av, int n);
int		ft_atoi(char *str);
int		read_content(int tail_size, int fd);
int		is_c_option(char *str);

void	tail_errno(char **av, int n)
{
	write(1, basename(av[0]), ft_strlen(basename(av[0])));
	write(1, ": ", 2);
	write(1, av[n], ft_strlen(av[n]));
	write(1, ": ", 2);
	write(1, strerror(errno), ft_strlen(strerror(errno)));
	write(1, "\n", 1);
}

int	tail_main(char **av, int first_f, int only_f, int n)
{
	int	fd;
	int	tail_size;

	tail_size = ft_atoi(av[2]);
	fd = open(av[n], O_RDWR);
	if (fd < 0 && errno != EISDIR)
		tail_errno(av, n);
	else
	{
		if (!first_f)
			write(1, "\n", 1);
		first_f = 0;
		if (!only_f)
		{
			write(1, "==> ", 4);
			write(1, av[n], ft_strlen(av[n]));
			write(1, " <==\n", 5);
		}
		if (fd < 0 && errno == EISDIR)
			return (first_f);
		read_content(tail_size, fd);
	}
	return (first_f);
}

void	require_arg(char **av)
{
	write(1, basename(av[0]), ft_strlen(basename(av[0])));
	write(1, ": option requires an arguments -- c\n", 36);
}

void	tail_files(int ac, char **av)
{
	int	n;
	int	only_f;
	int	first_f;

	n = 2;
	first_f = 1;
	only_f = 1;
	if (ac > 4)
		only_f = 0;
	while (++n < ac)
		first_f = tail_main(av, first_f, only_f, n);
}

int	main(int ac, char **av)
{
	int	n;
	int	tail_size;

	n = 2;
	if (ac == 2 && is_c_option(av[1]))
		require_arg(av);
	else if (ac >= 3 && is_c_option(av[1]))
	{
		tail_size = ft_atoi(av[2]);
		if (tail_size < 0)
		{
			tail_offset_error(av, n);
			return (0);
		}
		if (ac == 3)
			read_content(tail_size, 0);
		tail_files(ac, av);
	}
	return (0);
}
