/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:14:37 by seojyang          #+#    #+#             */
/*   Updated: 2023/01/29 18:04:19 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "stack.h"
#include "sort.h"
#include "check.h"
#include "triangle.h"
#include "operate.h"

void	make_structure(t_info *info, size_t size);
void	make_triangle(t_stacks *s, t_info *info);
void	combine_triangle(t_stacks *s, t_info *info);
void	free_all(t_list *a, t_list *b);

int	main(int ac, char **av)
{
	t_list		*a;
	t_list		*b;
	t_stacks	s;
	t_info		info;

	if (ac < 2)
		return (0);
	check_av(ac, av);
	a = make_list(ac, av);
	if (!a->size || is_sorted(a))
		exit(0);
	b = ft_lstnew('b');
	s.a = a;
	s.b = b;
	make_structure(&info, a->size);
	make_triangle(&s, &info);
	combine_triangle(&s, &info);
	ft_lstclear(&a, 0);
	free(b);
	return (0);
}

void	make_structure(t_info *info, size_t size)
{
	size_t	n;
	size_t	tmp_size;

	tmp_size = size;
	n = 0;
	info->depth = 0;
	info->arr_size = 1;
	while (more_depth(info->depth, size))
	{
		info->depth++;
		tmp_size /= 3;
		info->arr_size += three_power_n(info->depth);
	}
	info->structure = (int *)malloc(sizeof(int) * info->arr_size);
	info->shape = (int *)malloc(sizeof(int) * info->arr_size);
	info->structure[0] = size;
	if (info->depth % 2)
		info->shape[0] = 1;
	else
		info->shape[0] = 0;
	while (n < info->depth)
		design_struct(info, n++);
}

void	make_triangle(t_stacks *s, t_info *info)
{
	size_t	idx;

	idx = info->depth_start;
	if (info->arr_size <= 1)
		sort_under_5(s, info);
	else
	{
		while (idx < info->arr_size)
		{
			if (info->structure[idx] == 2)
				sort_tri_2(s, info->shape[idx]);
			else if (info->structure[idx] == 3)
				sort_tri_3(s, info->shape[idx]);
			else if (info->structure[idx] == 4)
				sort_tri_4(s, info->shape[idx]);
			else if (info->structure[idx] == 5)
				sort_tri_5(s, info->shape[idx]);
			else if (info->structure[idx] == 1)
				pb(s);
			idx++;
		}
	}
}

void	combine_triangle(t_stacks *s, t_info *info)
{
	size_t	times;

	times = 0;
	while (times <= info->depth)
	{
		if (times == info->depth)
		{
			if (times % 2 == 0)
				while (s->b->size)
					pa(s);
			break ;
		}
		shift_before_combine(s, info, times);
		merge(s, info, info->depth - times - 1, times);
		times++;
		info->depth_start = info->depth_start
			- three_power_n(info->depth - times);
	}
}
