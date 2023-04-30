/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:07:24 by seojyang          #+#    #+#             */
/*   Updated: 2023/01/17 13:36:37 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "stack.h"
#include "sort.h"
#include "operate.h"

void	sort_under_5(t_stacks *s, t_info *info)
{
	if (info->structure[0] == 1)
		return ;
	else if (info->structure[0] == 2)
	{
		if (s->a->head->data > s->a->head->next->data)
			sa(s);
		else
			return ;
	}
	else if (info->structure[0] == 3)
		sort_3(s);
	else if (info->structure[0] == 4)
		sort_4(s);
	else if (info->structure[0] == 5)
		sort_5(s);
}

void	sort_3(t_stacks *s)
{
	if (s->a->head->next->data < s->a->head->data
		&& s->a->head->next->data < s->a->last->data)
	{
		if (s->a->head->data < s->a->last->data)
			sa(s);
		else
			ra(s);
	}
	else if (s->a->last->data < s->a->head->data
		&& s->a->last->data < s->a->head->next->data)
	{
		if (s->a->head->data > s->a->head->next->data)
			sa(s);
		rra(s);
	}
	else
	{
		if (s->a->head->next->data > s->a->last->data)
		{
			ra(s);
			sa(s);
			rra(s);
		}
	}
}

void	sort_4(t_stacks *s)
{
	t_list	*a;

	a = s->a;
	if (is_most_4(a->head, a))
		pb(s);
	else if (is_most_4(a->head->next, a))
	{
		sa(s);
		pb(s);
	}
	else if (is_most_4(a->last->prev, a))
	{
		rra(s);
		rra(s);
		pb(s);
	}
	else if (is_most_4(a->last, a))
	{
		rra(s);
		pb(s);
	}
	sort_3(s);
	pa(s);
}

void	sort_5(t_stacks *s)
{
	t_list	*a;

	a = s->a;
	if (is_most_5_list(a->head, 0, a))
		pb(s);
	else if (is_most_5_list(a->head->next, 0, a))
	{
		sa(s);
		pb(s);
	}
	else if (is_most_5_list(a->head->next->next, 0, a))
	{
		ra(s);
		sa(s);
		pb(s);
	}
	else
		sort_5_norm(s);
	sort_4(s);
	pa(s);
}

void	sort_5_norm(t_stacks *s)
{
	t_list	*a;

	a = s->a;
	if (is_most_5_list(a->last->prev, 0, a))
	{
		rra(s);
		rra(s);
		pb(s);
	}
	else if (is_most_5_list(a->last, 0, a))
	{
		rra(s);
		pb(s);
	}
}
