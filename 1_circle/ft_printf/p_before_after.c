/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_before_after.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:59:56 by seojyang          #+#    #+#             */
/*   Updated: 2022/11/19 17:29:59 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_util.h"

void	before_malloc_precision(t_info *info, char *arg, size_t *arg_len)
{
	if (arg[0] == '-' || arg[0] == '+' || arg[0] == ' ')
		info->precision++;
	if (info->is_hash)
	{
		info->precision += 2;
		(*arg_len) += 2;
	}
}

void	after_malloc_precision(t_info info, char **arg, \
						char **precision, size_t *arg_len)
{
	char	*tmp;

	ft_memset(*precision, '0', info.precision);
	(*precision)[info.precision] = 0;
	if ((*arg)[0] == '-')
	{
		*arg = ft_strtrim(*arg, "-");
		(*precision)[0] = '-';
		(*arg_len)--;
	}
	if ((*arg)[0] == ' ' || (*arg)[0] == '+')
	{
		*arg = ft_strtrim(*arg, " +");
		(*precision)[0] = info.front;
		(*arg_len)--;
	}
	if (info.is_hash)
	{
		tmp = ft_strdup(*arg + 2);
		free(*arg);
		*arg = tmp;
		(*precision)[0] = '0';
		(*precision)[1] = 'x';
		(*arg_len) -= 2;
	}
}

void	after_malloc_width(t_info info, char **arg, \
					char **width, size_t *arg_len)
{
	char	*tmp;

	if (ft_strchr("iduxX", info.type) && info.width_fill == '0'
		&& ((*arg)[0] == '-' || (*arg)[0] == '+' || (*arg)[0] == ' '))
	{
		tmp = ft_chardup((*arg)[0]);
		(*width)[0] = (*arg)[0];
		*arg = ft_strtrim(*arg, tmp);
		free(tmp);
		(*arg_len)--;
	}
	if (info.is_hash && info.width_fill == '0')
	{
		tmp = ft_strdup(*arg + 2);
		free(*arg);
		*arg = tmp;
		(*width)[0] = '0';
		(*width)[1] = 'x';
		(*arg_len) -= 2;
	}
}
