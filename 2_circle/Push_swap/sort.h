/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:16:58 by seojyang          #+#    #+#             */
/*   Updated: 2023/01/17 13:45:39 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "libft/libft.h"
# include "stack.h"
# include "struct.h"

void	sort_tri_2(t_stacks *s, int shape);

void	sort_tri_3(t_stacks *s, int shape);
int		is_most_3(t_elem *it, int shape, t_elem *that, t_elem *that2);

void	sort_tri_4(t_stacks *s, int shape);
int		find_second(int shape, t_list *a);
int		is_more_than_second(t_elem *it, int second, int shape);
int		is_more(t_elem *it, t_elem *that, int shape);
void	make_2_2_push_last(t_stacks *s, int second, int shape);
void	make_2_2_push_head(t_stacks *s, int second, int shape);
void	sort_2_2_final(t_stacks *s, int shape);

void	sort_tri_5(t_stacks *s, int shape);
int		is_most_5_list(t_elem *it, int shape, t_list *list);
void	sort_tri_5_norm(t_stacks *s, int shape);

void	sort_under_5(t_stacks *s, t_info *info);
void	sort_3(t_stacks *s);
void	sort_4(t_stacks *s);
int		is_most_4(t_elem *it, t_list *a);
void	sort_5(t_stacks *s);
void	sort_5_norm(t_stacks *s);

#endif