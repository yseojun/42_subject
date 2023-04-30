/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operater_rotate_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:08:57 by seojyang          #+#    #+#             */
/*   Updated: 2023/01/17 16:45:26 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	ra(t_stacks *s)
{
	rotate(s->a);
	return (1);
}

int	rb(t_stacks *s)
{
	rotate(s->b);
	return (1);
}

int	rr(t_stacks *s)
{
	rotate(s->a);
	rotate(s->b);
	return (1);
}

int	rra(t_stacks *s)
{
	rev_rotate(s->a);
	return (1);
}

int	rrb(t_stacks *s)
{
	rev_rotate(s->b);
	return (1);
}
