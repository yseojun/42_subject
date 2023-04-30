/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:03:09 by seojyang          #+#    #+#             */
/*   Updated: 2023/01/29 16:23:21 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "triangle.h"
#include "stack.h"
#include "operate.h"
#include "sort.h"

void	shift_before_combine(t_stacks *s, t_info *info, size_t times)
{
	int		shift_size;
	size_t	to_do;
	size_t	last;

	to_do = three_power_n(info->depth - times);
	last = info->depth_start + to_do - 1;
	shift_size = 0;
	to_do /= 3;
	while (to_do--)
		shift_size += info->structure[last--];
	if (times % 2 != 0)
	{
		while (shift_size--)
			pb(s);
	}
	else
	{
		while (shift_size--)
			pa(s);
	}
}

void	merge(t_stacks *s, t_info *info, size_t n, size_t times)
{
	size_t	idx;
	size_t	to_do;
	int		shape;

	idx = make_next_idx(info, n);
	to_do = three_power_n(n);
	while (to_do--)
	{
		shape = info->shape[idx];
		while (info->structure[info->start]
			|| info->structure[info->mid] || info->structure[info->end])
		{
			if (times % 2 == 0)
				merge_to_a(s, info, shape);
			else
				merge_to_b(s, info, shape);
		}
		idx++;
		info->start++;
		info->mid--;
		info->end--;
	}
}

void	merge_to_a(t_stacks *s, t_info *info, int shape)
{
	if (info->structure[info->end] && \
	(!info->structure[info->mid] || is_more(s->a->last, s->b->head, shape)) && \
	(!info->structure[info->start] || is_more(s->a->last, s->b->last, shape)))
	{
		info->structure[info->end]--;
		rra(s);
	}
	else if (info->structure[info->mid] && \
	(!info->structure[info->end] || is_more(s->b->head, s->a->last, shape)) && \
	(!info->structure[info->start] || is_more(s->b->head, s->b->last, shape)))
	{
		info->structure[info->mid]--;
		pa(s);
	}
	else if (info->structure[info->start] && \
	(!info->structure[info->end] || is_more(s->b->last, s->a->last, shape)) && \
	(!info->structure[info->mid] || is_more(s->b->last, s->b->head, shape)))
	{
		info->structure[info->start]--;
		rrb(s);
		pa(s);
	}
}

void	merge_to_b(t_stacks *s, t_info *info, int shape)
{
	if (info->structure[info->end] && \
	(!info->structure[info->mid] || is_more(s->b->last, s->a->head, shape)) && \
	(!info->structure[info->start] || is_more(s->b->last, s->a->last, shape)))
	{
		info->structure[info->end]--;
		rrb(s);
	}
	else if (info->structure[info->mid] && \
	(!info->structure[info->end] || is_more(s->a->head, s->b->last, shape)) && \
	(!info->structure[info->start] || is_more(s->a->head, s->a->last, shape)))
	{
		info->structure[info->mid]--;
		pb(s);
	}
	else if (info->structure[info->start] && \
	(!info->structure[info->end] || is_more(s->a->last, s->b->last, shape)) && \
	(!info->structure[info->mid] || is_more(s->a->last, s->a->head, shape)))
	{
		info->structure[info->start]--;
		rra(s);
		pb(s);
	}
}
