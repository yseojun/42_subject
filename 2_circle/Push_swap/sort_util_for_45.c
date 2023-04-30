/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util_for_45.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:29:55 by seojyang          #+#    #+#             */
/*   Updated: 2023/01/17 13:54:57 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack.h"
#include "operate.h"

void	make_2_2_push_last(t_stacks *s, int second, int shape)
{
	rra(s);
	pb(s);
	if (is_more_than_second(s->a->last, second, shape))
	{
		if (s->a->size > 1)
			rra(s);
		pb(s);
	}
	else
	{
		if (is_more_than_second(s->a->head->next, second, shape))
			sa(s);
		pb(s);
		if (s->a->size > 1)
			rra(s);
	}
}

void	make_2_2_push_head(t_stacks *s, int second, int shape)
{
	if (is_more_than_second(s->a->head, second, shape))
	{
		pb(s);
		if (is_more_than_second(s->a->head, second, shape))
			pb(s);
	}
	else
	{
		sa(s);
		pb(s);
	}
	rra(s);
	rra(s);
	if (is_more_than_second(s->a->head, second, shape))
		pb(s);
}

int	is_most_5_list(t_elem *it, int shape, t_list *list)
{
	int	data;

	data = it->data;
	if (shape == 1)
		return (data >= list->last->data && data >= list->last->prev->data
			&& data >= list->head->data && data >= list->head->next->data
			&& data >= list->head->next->next->data);
	else
		return (data <= list->last->data && data <= list->last->prev->data
			&& data <= list->head->data && data <= list->head->next->data
			&& data <= list->head->next->next->data);
}

void	sort_tri_5_norm(t_stacks *s, int shape)
{
	if (is_most_5_list(s->a->last, shape, s->a))
	{
		rra(s);
		pb(s);
		ra(s);
	}
	else if (is_most_5_list(s->a->last->prev, shape, s->a))
	{
		rra(s);
		rra(s);
		pb(s);
		ra(s);
		ra(s);
	}
}
