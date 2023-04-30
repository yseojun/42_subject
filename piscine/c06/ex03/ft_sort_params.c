/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:04:10 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/04 19:00:24 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	n;

	n = 0;
	while (s1 && s2)
	{
		if (s1[n] != s2[n])
			break ;
		n++;
	}
	return (s1[n] - s2[n]);
}

void	put_once(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	int		n;
	char	*tmp;	

	n = 1;
	while (n < ac - 1)
	{
		if (ft_strcmp(av[n], av[n + 1]) > 0)
		{
			tmp = av[n];
			av[n] = av[n + 1];
			av[n + 1] = tmp;
			n = 0;
		}
		n++;
	}
	n = 1;
	while (n < ac)
	{
		put_once(av[n]);
		n++;
	}
	return (0);
}
