/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:43:48 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/01 22:59:24 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_prtable(char c)
{
	if (32 <= c && c <= 126)
		return (1);
	return (0);
}

void	ft_putstr_non_printable(char *str)
{
	int		n;
	char	*hex;

	n = 0;
	hex = "0123456789abcdef";
	while (str[n])
	{
		if (!is_prtable(str[n]))
		{
			write(1, "\\", 1);
			write(1, &hex[(unsigned char)str[n] / 16], 1);
			write(1, &hex[(unsigned char)str[n] % 16], 1);
		}
		else
			write(1, &str[n], 1);
		n++;
	}
}
