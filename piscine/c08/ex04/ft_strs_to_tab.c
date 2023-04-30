/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:43:27 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/10 20:42:30 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

char	*ft_strdup(char *str)
{
	char	*new;
	int		n;

	n = ft_strlen(str);
	new = (char *)malloc(sizeof(char) * (n + 1));
	if (!new)
		return (0);
	n = 0;
	while (str[n])
	{
		new[n] = str[n];
		n++;
	}
	new[n] = '\0';
	return (new);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*arr;
	int			n;

	n = 0;
	arr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!arr)
		return (0);
	while (n < ac)
	{
		arr[n].size = ft_strlen(av[n]);
		arr[n].str = av[n];
		arr[n].copy = ft_strdup(av[n]);
		n++;
	}
	arr[n].str = 0;
	return (arr);
}
