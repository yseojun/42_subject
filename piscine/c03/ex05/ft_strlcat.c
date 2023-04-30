/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 11:06:05 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/03 11:25:36 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	lenlen(char *str)
{
	unsigned int	n;

	n = 0;
	while (*(str++))
		n++;
	return (n);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	m;
	unsigned int	dl;

	m = 0;
	dl = lenlen(dest);
	if (dl >= size)
		return (size + lenlen(src));
	while (src[m] && dl + m + 1 < size)
	{
		dest[dl + m] = src[m];
		m++;
	}
	dest[dl + m] = '\0';
	return (dl + lenlen(src));
}
