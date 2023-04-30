/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:01:01 by seojyang          #+#    #+#             */
/*   Updated: 2022/11/19 13:59:21 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_util.h"

static size_t	chk_len(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char		*output;
	size_t		len;

	len = chk_len(n);
	output = (char *)malloc(len + 1);
	if (output)
	{
		output[len] = '\0';
		if (n == 0)
			output[0] = '0';
		while (len-- > 0 && n)
		{
			output[len] = n % 10 + '0';
			n /= 10;
		}
	}
	return (output);
}
