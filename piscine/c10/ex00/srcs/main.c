/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:50:33 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/13 15:27:05 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	error_prt(int ac)
{
	if (ac == 1)
		write(1, "File name missing.\n", 19);
	else if (ac > 2)
		write(1, "Too many arguments.\n", 20);
}

int	main(int ac, char **av)
{
	int		fd;
	int		rbyte;
	char	buf[1024];

	if (ac != 2)
		error_prt(ac);
	else
	{
		fd = open(av[1], O_RDONLY);
		rbyte = read(fd, buf, 1024);
		while (rbyte)
		{
			if (rbyte < 0)
			{
				write(1, "Cannot read file.\n", 18);
				break ;
			}
			write(1, buf, rbyte);
			rbyte = read(fd, buf, 1024);
		}
		close(fd);
	}
	return (0);
}
