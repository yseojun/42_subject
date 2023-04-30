/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_info.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:56:35 by seojyang          #+#    #+#             */
/*   Updated: 2022/11/19 14:02:56 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_util.h"

void	make_info(const char *str, unsigned int *idx, t_info *info)
{
	while (!info->type)
	{
		if (str[*idx] != '0' && ft_isdigit(str[*idx]))
			info->width = make_size(str, idx);
		else if (str[*idx] == '.')
		{
			info->is_precision = 1;
			(*idx)++;
			info->precision = make_size(str, idx);
		}
		else if (str[*idx] == ' ')
			info->front = ' ';
		else if (str[*idx] == '+')
			info->front = '+';
		else if (str[*idx] == '#')
			info->is_hash = 1;
		else if (str[*idx] == '-')
			info->is_left = 1;
		else if (str[*idx] == '0')
			info->width_fill = '0';
		else if (ft_strchr("cspdiuxX%", str[*idx]))
			info->type = str[*idx];
		(*idx)++;
	}
}

size_t	make_size(const char *str, unsigned int *idx)
{
	size_t	size;

	size = 0;
	while (ft_isdigit(str[*idx]))
		size = size * 10 + str[(*idx)++] - '0';
	(*idx)--;
	return (size);
}

void	edit_info(t_info *info, char *arg)
{
	if (info->front == ' ')
	{
		if (info->type == 's')
			info->front = 0;
		if ((info->type == 'i' || info->type == 'd')
			&& arg[0] == '-')
			info->front = 0;
	}
	else if (info->front == '+')
	{
		if ((info->type == 'i' || info->type == 'd')
			&& arg[0] == '-')
			info->front = 0;
	}
	if (info->is_hash && ft_strlen(arg) <= 1)
		info->is_hash = 0;
}

void	init_info(t_info *info)
{
	info->type = 0;
	info->width = 0;
	info->precision = 0;
	info->width_fill = ' ';
	info->is_left = 0;
	info->is_hash = 0;
	info->is_zero = 0;
	info->front = 0;
	info->is_null = 0;
	info->is_precision = 0;
}
