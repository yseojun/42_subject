/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:50:52 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/04 18:55:40 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	n;

	n = 0;
	if (ac < 1)
		return (0);
	while (av[0][n])
		write(1, &av[0][n++], 1);
	write(1, "\n", 1);
	return (0);
}
