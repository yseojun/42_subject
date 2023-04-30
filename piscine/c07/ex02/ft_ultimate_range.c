/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:18:42 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/09 18:36:55 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	n;

	size = max - min;
	if (max <= min)
	{
		*range = 0;
		return (0);
	}
	*range = (int *)malloc(sizeof(int) * size);
	if (!range)
		return (-1);
	n = 0;
	while (min < max)
		*(*range + n++) = min++;
	return (size);
}
/*
#include <stdio.h>
int main()
{
	int	*arr;
	int i;

	i = 0;
	ft_ultimate_range(&arr, 2, 14);
	while (arr[i])
		printf("%d\n", arr[i++]);
}
*/
