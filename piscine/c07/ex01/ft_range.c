/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:18:23 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/09 18:37:15 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	range;
	int	n;

	range = max - min;
	if (max <= min)
		return (0);
	arr = (int *)malloc(sizeof(int) * range);
	if (!arr)
		return (0);
	n = 0;
	while (min < max)
		arr[n++] = min++;
	return (arr);
}
/*
#include <stdio.h>
int main ()
{
	int i;
	int *arr;

	arr = ft_range(1,11);
	i = 0;
	while (arr[i])
		printf("%d", arr[i++]);
}
*/
