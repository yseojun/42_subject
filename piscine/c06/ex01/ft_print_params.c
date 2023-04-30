/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:56:13 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/04 18:55:33 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	n;
	int	i;

	n = 1;
	while (n < ac)
	{
		i = 0;
		while (av[n][i])
			write(1, &av[n][i++], 1);
		write(1, "\n", 1);
		n++;
	}
	return (0);
}
