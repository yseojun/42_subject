/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util_for_34.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:29:55 by seojyang          #+#    #+#             */
/*   Updated: 2023/01/16 21:52:06 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack.h"
#include "operate.h"

int	is_most_3(t_elem *it, int shape, t_elem *that, t_elem *that2)
{
	if (shape == 1)
		return (it->data > that->data && it->data > that2->data);
	else
		return (it->data < that->data && it->data < that2->data);
}

int	is_most_4(t_elem *it, t_list *a)
{
	return (it->data <= a->head->data && it->data <= a->head->next->data
		&& it->data <= a->last->data && it->data <= a->last->prev->data);
}

int	is_more(t_elem *it, t_elem *that, int shape)
{
	if (shape == 1)
		return (it->data >= that->data);
	else
		return (it->data <= that->data);
}

int	is_more_than_second(t_elem *it, int second, int shape)
{
	if (shape == 1)
		return (it->data >= second);
	else
		return (it->data <= second);
}

int	find_second(int shape, t_list *a)
{
	int	arr[4];
	int	tmp;
	int	idx;

	arr[0] = a->head->data;
	arr[1] = a->head->next->data;
	arr[2] = a->last->prev->data;
	arr[3] = a->last->data;
	idx = 0;
	while (idx < 3)
	{
		if (arr[idx] > arr[idx + 1])
		{
			tmp = arr[idx];
			arr[idx] = arr[idx + 1];
			arr[idx + 1] = tmp;
			idx = -1;
		}
		idx++;
	}
	if (shape == 1)
		return (arr[2]);
	else
		return (arr[1]);
}
