/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:15:16 by seojyang          #+#    #+#             */
/*   Updated: 2022/11/19 17:38:02 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_util.h"

char	*make_for_string(t_info info, char *arg)
{
	char	*precision;

	precision = malloc(info.precision + 1);
	if (!precision)
		return (0);
	ft_strlcpy(precision, arg, info.precision + 1);
	return (precision);
}

char	*edit_arg(t_info *info, va_list ap)
{
	char	*arg;
	char	*for_front;

	arg = make_arg(*info, ap);
	if (info->type == 'c' && arg[0] == 0)
		info->is_null = 1;
	if (info->type == 'x' || info->type == 'X')
		arg = make_hash(info, arg);
	edit_info(info, arg);
	if (info->front)
	{
		for_front = ft_chardup(info->front);
		if (arg[0] == '0' && info->is_precision && !info->precision)
			arg = ft_strtrim(arg, "0");
		arg = ft_strjoin(for_front, arg);
		free(for_front);
	}
	if (info->is_precision)
		arg = combine_precision(*info, arg);
	arg = combine_width(*info, arg);
	if (info->type == 'X')
		arg = make_upper(arg);
	return (arg);
}

void	print_arg(t_info info, int *len, char *arg)
{
	*len += ft_strlen(arg);
	if (info.is_null)
	{
		if (info.is_left)
		{
			ft_putchar_fd(0, 1);
			*len += ft_strlen(arg + 1);
		}
		ft_putstr_fd(arg + info.is_left, 1);
		if (!info.is_left)
			ft_putchar_fd(0, 1);
		(*len)++;
	}
	else
		ft_putstr_fd(arg, 1);
	free(arg);
}

void	put_percent(const char *str, unsigned int *idx, va_list ap, int *len)
{
	t_info		info;

	(*idx)++;
	init_info(&info);
	make_info(str, idx, &info);
	print_arg(info, len, edit_arg(&info, ap));
}

int	ft_printf(const char *str, ...)
{
	unsigned int	idx;
	int				len;
	va_list			ap;

	idx = 0;
	len = 0;
	va_start(ap, str);
	while (str[idx])
	{
		if (str[idx] == '%')
			put_percent(str, &idx, ap, &len);
		else
		{
			write(1, &str[idx++], 1);
			len++;
		}
	}
	return (len);
}
