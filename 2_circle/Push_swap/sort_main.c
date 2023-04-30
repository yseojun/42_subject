/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:18:52 by seojyang          #+#    #+#             */
/*   Updated: 2023/01/17 13:53:30 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack.h"
#include "struct.h"
#include "operate.h"

void	sort_tri_2(t_stacks *s, int shape)
{
	if ((shape ^ (s->a->head->data > s->a->head->next->data)) == 1)
		sa(s);
	pb(s);
	pb(s);
}

void	sort_tri_3(t_stacks *s, int shape)
{
	if (is_most_3(s->a->last, shape, s->a->head, s->a->head->next))
	{
		rra(s);
		pb(s);
	}
	else
	{
		if (is_most_3(s->a->head->next, shape, s->a->head, s->a->last))
			sa(s);
		pb(s);
		rra(s);
	}
	sort_tri_2(s, shape);
}

void	sort_tri_4(t_stacks *s, int shape)
{
	int	second;

	second = find_second(shape, s->a);
	if (is_more_than_second(s->a->last, second, shape))
		make_2_2_push_last(s, second, shape);
	else
		make_2_2_push_head(s, second, shape);
	if ((shape ^ (s->b->head->data > s->b->head->next->data)) == 0)
	{
		if ((shape ^ (s->a->head->data < s->a->head->next->data)) == 0)
			ss(s);
		else
			sb(s);
	}
	else
		if ((shape ^ (s->a->head->data < s->a->head->next->data)) == 0)
			sa(s);
	pb(s);
	pb(s);
}

void	sort_tri_5(t_stacks *s, int shape)
{
	if (is_most_5_list(s->a->head, shape, s->a))
		pb(s);
	else if (is_most_5_list(s->a->head->next, shape, s->a))
	{
		sa(s);
		pb(s);
	}
	else if (is_most_5_list(s->a->head->next->next, shape, s->a))
	{
		ra(s);
		sa(s);
		pb(s);
		rra(s);
	}
	else
		sort_tri_5_norm(s, shape);
	sort_tri_4(s, shape);
}
