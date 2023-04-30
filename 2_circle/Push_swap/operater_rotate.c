/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operater_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:08:57 by seojyang          #+#    #+#             */
/*   Updated: 2023/01/17 16:41:31 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operate.h"
#include "stack.h"

int	ra(t_stacks *s)
{
	ft_putendl_fd("ra", 1);
	rotate(s->a);
	return (1);
}

int	rb(t_stacks *s)
{
	ft_putendl_fd("rb", 1);
	rotate(s->b);
	return (1);
}

int	rr(t_stacks *s)
{
	ft_putendl_fd("rr", 1);
	rotate(s->a);
	rotate(s->b);
	return (1);
}

int	rra(t_stacks *s)
{
	ft_putendl_fd("rra", 1);
	rev_rotate(s->a);
	return (1);
}

int	rrb(t_stacks *s)
{
	ft_putendl_fd("rrb", 1);
	rev_rotate(s->b);
	return (1);
}
