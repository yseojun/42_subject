/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:42:30 by seojyang          #+#    #+#             */
/*   Updated: 2023/01/29 17:11:57 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "../libft/libft.h"

typedef struct s_stacks
{
	struct s_list	*a;
	struct s_list	*b;
}	t_stacks;

t_list	*make_list(int ac, char **av);
t_elem	*pophead(t_list *list);
t_elem	*poplast(t_list *list);

void	add_back_of_head(t_list *list, t_elem *elem);
int		is_digit(char *str);
void	check_av(int ac, char **av);
void	error_fin(void);
void	chk_double(t_list **list, t_elem *new);
void	make_for_multiple_av(char *av, t_list *new_list);
int		is_sorted(t_list *a);

int		swap(t_list *list);
int		push(t_list *throwball, t_list *catchball);
int		rotate(t_list *list);
int		rev_rotate(t_list *list);

int		pa(t_stacks *s);
int		pb(t_stacks *s);
int		sa(t_stacks *s);
int		sb(t_stacks *s);
int		ss(t_stacks *s);
int		ra(t_stacks *s);
int		rb(t_stacks *s);
int		rr(t_stacks *s);
int		rra(t_stacks *s);
int		rrb(t_stacks *s);
int		rrr(t_stacks *s);

#endif