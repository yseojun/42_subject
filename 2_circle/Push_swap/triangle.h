/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:04:11 by seojyang          #+#    #+#             */
/*   Updated: 2023/01/17 13:41:07 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_H
# define TRIANGLE_H

# include "libft/libft.h"
# include "struct.h"
# include "stack.h"

void	combine_triangle(t_stacks *s, t_info *info);
void	shift_before_combine(t_stacks *s, t_info *info, size_t times);
void	merge(t_stacks *s, t_info *info, size_t n, size_t times);
void	merge_to_a(t_stacks *s, t_info *info, int shape);
void	merge_to_b(t_stacks *s, t_info *info, int shape);

#endif