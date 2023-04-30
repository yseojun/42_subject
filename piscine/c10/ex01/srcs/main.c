/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:50:33 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/14 19:22:44 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/errno.h>
#include <string.h>
#include <libgen.h>

int	ft_strlen(char *str);
int	is_input(char *av);

void	cat_input(void)
{
	int		l;
	char	buf[1024];

	l = read(0, buf, 1024);
	while (l)
	{
		if (l <= 0)
			return ;
		write(1, buf, l);
		l = read(0, buf, 1024);
	}
}

void	cat_errno(char **av, int n)
{
	int		errno;

	write(1, basename(av[0]), ft_strlen(basename(av[0])));
	write(1, ": ", 2);
	write(1, av[n], ft_strlen(av[n]));
	write(1, ": ", 2);
	write(1, strerror(errno), ft_strlen(strerror(errno)));
	write(1, "\n", 1);
}			

void	cat_read_file(int fd)
{
	char	buf[1024];
	int		rbyte;

	rbyte = read(fd, buf, 1024);
	while (rbyte)
	{
		write(1, buf, rbyte);
		rbyte = read(fd, buf, 1024);
	}
}

int	mod_error(char *av)
{
	int	errno;
	int	fd_rw;
	int	fd_ro;

	fd_rw = open(av, O_RDWR);
	if (fd_rw < 0 && errno == EISDIR)
		return (fd_rw);
	close(fd_rw);
	fd_ro = open(av, O_RDONLY);
	return (fd_ro);
}

int	main(int ac, char **av)
{
	int	n;
	int	fd;

	if (ac == 1)
		cat_input();
	else
	{
		n = 1;
		while (n < ac)
		{
			if (is_input(av[n]))
				cat_input();
			else
			{
				fd = mod_error(av[n]);
				if (fd < 0)
					cat_errno(av, n);
				else
					cat_read_file(fd);
				close(fd);
			}
			n++;
		}
	}
	return (0);
}
