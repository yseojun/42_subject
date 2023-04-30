/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:08:44 by seojyang          #+#    #+#             */
/*   Updated: 2022/11/19 14:00:59 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_util.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	idx;

	if (!dst && !src)
		return (0);
	idx = 0;
	while (idx < n)
	{
		*((unsigned char *) dst + idx) = *((unsigned char *) src + idx);
		idx++;
	}
	return (dst);
}

void	*ft_memset(void *b, int c, int len)
{
	unsigned char	*tmp;

	tmp = (unsigned char *) b;
	while (len--)
		*tmp++ = (unsigned char) c;
	return (b);
}
