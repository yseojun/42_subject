/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:06:16 by seojyang          #+#    #+#             */
/*   Updated: 2023/02/09 13:50:18 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_bonus.h"

void	free_arr(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	is_digit(char *str)
{
	int			idx;
	long long	ans;

	idx = 0;
	ans = 0;
	while ((9 <= str[idx] && str[idx] <= 13) || str[idx] == 32)
		idx++;
	if (str[idx] == '-' || str[idx] == '+')
		idx++;
	while (str[idx])
	{
		if (!ft_isdigit(str[idx]))
			return (0);
		ans = ans * 10 + str[idx] - '0';
		if (ans > 2147483647 && !(ans == -2147483648 && str[0] == '-'))
			return (0);
		idx++;
	}
	if (idx == 0)
		return (0);
	idx--;
	if ((str[idx] == ' ' || str[idx] == '+' || str[idx] == '-'))
		return (0);
	else
		return (1);
}

int	is_hex(char c)
{
	return (ft_isdigit(c) || ('a' <= c && c <= 'f') || ('A' <= c && c <= 'F'));
}

int	is_color(char *str)
{
	int			idx;
	long long	ans;

	idx = 0;
	ans = 0;
	while (str[idx])
		idx++;
	if (idx < 3 && !(str[0] == '0' && str[1] == 'x'))
		return (0);
	idx = 2;
	while (str[idx])
	{
		if (!is_hex(str[idx]))
			return (0);
		if (ft_isdigit(str[idx]))
			ans = ans * 16 + str[idx] - '0';
		else if ('a' <= str[idx] && str[idx] <= 'f')
			ans = ans * 16 + str[idx] - 'a' + 10;
		else if ('A' <= str[idx] && str[idx] <= 'F')
			ans = ans * 16 + str[idx] - 'A' + 10;
		if (ans > 2147483647 && !(ans == -2147483648 && str[0] == '-'))
			return (0);
		idx++;
	}
	return (1);
}

int	atohex(char *str)
{
	int			idx;
	long long	ans;

	ans = 0;
	idx = 2;
	while (str[idx])
	{
		if (ft_isdigit(str[idx]))
			ans = ans * 16 + str[idx] - '0';
		else if ('a' <= str[idx] && str[idx] <= 'f')
			ans = ans * 16 + str[idx] - 'a' + 10;
		else if ('A' <= str[idx] && str[idx] <= 'F')
			ans = ans * 16 + str[idx] - 'a' + 10;
		if (ans > 2147483647 && !(ans == -2147483648 && str[0] == '-'))
			return (0);
		idx++;
	}
	return (ans);
}
