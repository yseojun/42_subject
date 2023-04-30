/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:28:31 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/12 00:22:13 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*new;
	int	n;

	new = (int *)malloc(sizeof(int) * length);
	if (!new)
		return (0);
	n = 0;
	while (n < length)
	{
		new[n] = f(tab[n]);
		n++;
	}
	return (new);
}
