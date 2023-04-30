/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:48:45 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/20 13:53:48 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <sys/errno.h>

int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	ft_strcat(char *s1, char *s2);

void	tail_offset_error(char **av, int n)
{
	write(1, basename(av[0]), ft_strlen(basename(av[0])));
	write(1, ": illegal offset -- ", 20);
	write(1, av[n], ft_strlen(av[n]));
	write(1, "\n", 1);
}

char	*ft_newstr(char *s1, char *s2)
{
	char	*new;
	int		size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = (char *)malloc(sizeof(char) * size);
	if (!new)
		return (0);
	new[0] = '\0';
	ft_strcat(new, s1);
	ft_strcat(new, s2);
	free(s1);
	free(s2);
	return (new);
}

int	read_content(int tail_size, int fd)
{
	char	*new;
	char	*buf;
	int		real_size;
	int		buf_size;

	buf = (char *)malloc(sizeof(char) * 4001);
	buf[4000] = '\0';
	new = (char *)malloc(sizeof(char));
	new[0] = '\0';
	real_size = 0;
	buf_size = read(fd, buf, 4000);
	while (buf_size)
	{
		real_size += buf_size;
		new = ft_newstr(new, buf);
		buf = (char *)malloc(sizeof(char) * 4001);
		buf[buf_size] = '\0';
		buf_size = read(fd, buf, 4000);
	}
	if (real_size >= tail_size)
		write(1, new + real_size - tail_size, tail_size);
	else
		write(1, new, real_size);
	free(new);
	return (0);
}
