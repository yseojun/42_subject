/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 12:07:50 by seojyang          #+#    #+#             */
/*   Updated: 2023/01/29 17:15:45 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	cal_struct(t_info *info, size_t idx)
{
	size_t	remain;

	remain = 0;
	if (info->structure[idx] % 3 == 2)
		remain = 1;
	info->structure[info->start] = info->structure[idx] / 3 + remain;
	if (info->structure[idx] % 3)
		remain = 1;
	info->structure[info->mid] = info->structure[idx] / 3 + remain;
	info->structure[info->end] = info->structure[idx] / 3;
	info->shape[info->start] = info->shape[idx];
	info->shape[info->mid] = !info->shape[idx];
	info->shape[info->end] = !info->shape[idx];
}

int	make_next_idx(t_info *info, size_t n)
{
	size_t	power;
	size_t	idx;

	power = three_power_n(n);
	idx = (power - 1) / 2;
	info->start = idx + power;
	info->mid = info->start + power * 2 - 1;
	info->end = info->mid + power;
	return (idx);
}

void	design_struct(t_info *info, size_t n)
{
	size_t	last;
	size_t	idx;

	idx = make_next_idx(info, n);
	info->depth_start = info->start;
	last = info->start - 1;
	while (idx <= last)
	{
		cal_struct(info, idx);
		info->start++;
		info->mid--;
		info->end--;
		idx++;
	}
}

int	more_depth(size_t depth, size_t size)
{
	size_t	max;

	max = 5;
	while (depth--)
		max *= 3;
	return (max < size);
}

size_t	three_power_n(size_t n)
{
	size_t	ans;

	ans = 1;
	while (n--)
		ans *= 3;
	return (ans);
}
