/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:40:09 by seojyang          #+#    #+#             */
/*   Updated: 2023/01/17 15:04:58 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATE_H
# define OPERATE_H

# include "libft/libft.h"
# include "stack.h"

int	swap(t_list *list);
int	push(t_list *throwball, t_list *catchball);
int	rotate(t_list *list);
int	rev_rotate(t_list *list);

int	pa(t_stacks *s);
int	pb(t_stacks *s);
int	sa(t_stacks *s);
int	sb(t_stacks *s);
int	ss(t_stacks *s);
int	ra(t_stacks *s);
int	rb(t_stacks *s);
int	rr(t_stacks *s);
int	rra(t_stacks *s);
int	rrb(t_stacks *s);
int	rrr(t_stacks *s);

#endif