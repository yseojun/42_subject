/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operater_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:02:30 by seojyang          #+#    #+#             */
/*   Updated: 2023/01/17 16:41:33 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "operate.h"

int	swap(t_list *list)
{
	if (list->size < 2)
		return (0);
	add_back_of_head(list, pophead(list));
	return (1);
}

int	push(t_list *from, t_list *to)
{
	if (!from->size)
		return (0);
	ft_lstadd_front(&to, pophead(from));
	from->size--;
	to->size++;
	return (1);
}

int	rotate(t_list *list)
{
	if (list->size < 2)
		return (0);
	ft_lstadd_back(&list, pophead(list));
	return (1);
}

int	rev_rotate(t_list *list)
{
	if (list->size < 2)
		return (0);
	ft_lstadd_front(&list, poplast(list));
	return (1);
}

int	rrr(t_stacks *s)
{
	ft_putendl_fd("rrr", 1);
	rev_rotate(s->a);
	rev_rotate(s->b);
	return (1);
}
