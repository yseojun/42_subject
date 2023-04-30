/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operater_push_swap_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:44:45 by seojyang          #+#    #+#             */
/*   Updated: 2023/01/17 16:45:21 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	pa(t_stacks *s)
{
	push(s->b, s->a);
	return (1);
}

int	pb(t_stacks *s)
{
	push(s->a, s->b);
	return (1);
}

int	ss(t_stacks *s)
{
	swap(s->a);
	swap(s->b);
	return (1);
}

int	sa(t_stacks *s)
{
	swap(s->a);
	return (1);
}

int	sb(t_stacks *s)
{
	swap(s->b);
	return (1);
}
