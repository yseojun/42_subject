/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:15:09 by seojyang          #+#    #+#             */
/*   Updated: 2023/01/29 17:14:26 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "libft/libft.h"

typedef struct s_info
{
	int		*structure;
	int		*shape;
	size_t	arr_size;
	size_t	depth;
	size_t	start;
	size_t	mid;
	size_t	end;
	size_t	depth_start;
}		t_info;

int		more_depth(size_t depth, size_t size);
int		make_next_idx(t_info *info, size_t n);
size_t	three_power_n(size_t n);
void	cal_size(t_info *info, size_t idx);
void	cal_shape(t_info *info, size_t idx);
void	design_struct(t_info *info, size_t n);

#endif