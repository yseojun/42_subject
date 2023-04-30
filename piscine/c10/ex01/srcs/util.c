/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:33:10 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/13 14:33:46 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

int	is_input(char *av)
{
	int	n;

	n = 0;
	while (av[n])
		n++;
	if (n != 1)
		return (0);
	if (av[0] == '-')
		return (1);
	return (0);
}
