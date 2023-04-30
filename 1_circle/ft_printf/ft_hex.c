/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:01:01 by seojyang          #+#    #+#             */
/*   Updated: 2022/11/19 17:38:39 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_util.h"

static size_t	chk_len(unsigned long long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*ft_ultohex(unsigned long long n)
{
	char		*output;
	size_t		len;
	const char	*hex = "0123456789abcdef";

	len = chk_len(n);
	output = (char *)malloc(len + 1);
	if (output)
	{
		output[len] = '\0';
		if (n == 0)
			output[0] = '0';
		while (len-- > 0 && n)
		{
			output[len] = (char) hex[n % 16];
			n /= 16;
		}
	}
	return (output);
}

char	*ft_uitohex(unsigned int n)
{
	char		*output;
	size_t		len;
	const char	*hex = "0123456789abcdef";

	len = chk_len(n);
	output = (char *)malloc(len + 1);
	if (output)
	{
		output[len] = '\0';
		if (n == 0)
			output[0] = '0';
		while (len-- > 0 && n)
		{
			output[len] = (char) hex[n % 16];
			n /= 16;
		}
	}
	return (output);
}
