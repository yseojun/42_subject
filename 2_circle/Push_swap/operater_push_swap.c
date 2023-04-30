/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operater_push_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:44:45 by seojyang          #+#    #+#             */
/*   Updated: 2023/01/17 16:41:32 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "operate.h"

int	pa(t_stacks *s)
{
	ft_putendl_fd("pa", 1);
	push(s->b, s->a);
	return (1);
}

int	pb(t_stacks *s)
{
	ft_putendl_fd("pb", 1);
	push(s->a, s->b);
	return (1);
}

int	ss(t_stacks *s)
{
	ft_putendl_fd("ss", 1);
	swap(s->a);
	swap(s->b);
	return (1);
}

int	sa(t_stacks *s)
{
	ft_putendl_fd("sa", 1);
	swap(s->a);
	return (1);
}

int	sb(t_stacks *s)
{
	ft_putendl_fd("sb", 1);
	swap(s->b);
	return (1);
}
