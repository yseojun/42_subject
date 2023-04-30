/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:24:45 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/01 15:45:36 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prt(char c)
{
	if (32 <= c && c <= 126)
		return (1);
	return (0);
}

int	ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (!is_prt(*str))
			return (0);
		str++;
	}
	return (1);
}
