/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_make.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:05:12 by seojyang          #+#    #+#             */
/*   Updated: 2022/11/19 17:29:50 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_util.h"

char	*make_arg(t_info info, va_list ap)
{
	char	*chars;

	if (info.type == 'i' || info.type == 'd')
		return (ft_itoa(va_arg(ap, int)));
	else if (info.type == '%')
		return (ft_strdup("%"));
	else if (info.type == 'u')
		return (ft_uitoa(va_arg(ap, unsigned int)));
	else if (info.type == 'x' || info.type == 'X')
		return (ft_uitohex(va_arg(ap, unsigned int)));
	else if (info.type == 's')
	{
		chars = va_arg(ap, char *);
		if (!chars)
			return (ft_strdup("(null)"));
		return (ft_strdup(chars));
	}
	else if (info.type == 'c')
		return (ft_chardup(va_arg(ap, int)));
	else if (info.type == 'p')
		return (ft_strjoin("0x", ft_ultohex(va_arg(ap, long long))));
	else
		return (0);
}

char	*combine_precision(t_info info, char *arg)
{
	char	*precision;
	size_t	arg_len;

	precision = 0;
	arg_len = ft_strlen(arg);
	if (info.is_hash)
		arg_len -= 2;
	if (info.type == 's' && arg_len > info.precision)
		precision = make_for_string(info, arg);
	else if (!info.is_hash && ft_strchr("iduxXp", info.type)
		&& arg[0] == '0' && !info.precision)
		precision = ft_strdup("");
	else if (ft_strchr("iduxX", info.type) && arg_len <= info.precision)
	{
		before_malloc_precision(&info, arg, &arg_len);
		precision = (char *)malloc(info.precision + 1);
		if (!precision)
			return (0);
		after_malloc_precision(info, &arg, &precision, &arg_len);
		ft_memcpy(precision + info.precision - arg_len, arg, arg_len);
	}
	else
		precision = ft_strdup(arg);
	free(arg);
	return (precision);
}

char	*combine_width(t_info info, char *arg)
{
	char	*width;
	size_t	arg_len;

	arg_len = ft_strlen(arg);
	if (info.type == 'c' && !arg_len)
		arg_len++;
	if (arg_len < info.width)
	{
		width = (char *)malloc(info.width + 1);
		if (!width)
			return (0);
		if (info.is_precision || info.is_left)
			info.width_fill = ' ';
		ft_memset(width, info.width_fill, info.width);
		width[info.width] = 0;
		after_malloc_width(info, &arg, &width, &arg_len);
		if (info.is_left)
			ft_memcpy(width, arg, arg_len);
		else
			ft_memcpy(width + info.width - arg_len, arg, arg_len);
	}
	else
		width = ft_strdup(arg);
	free(arg);
	return (width);
}

char	*make_hash(t_info *info, char *arg)
{
	if (info->is_hash && arg[0] != '0')
	{
		arg = ft_strjoin("0x", arg);
		info->front = 0;
	}
	return (arg);
}

char	*make_upper(char *arg)
{
	unsigned int	idx;

	idx = 0;
	while (arg[idx])
	{
		arg[idx] = ft_toupper(arg[idx]);
		idx++;
	}
	return (arg);
}
