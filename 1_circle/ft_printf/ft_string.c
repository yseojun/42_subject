/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:18:07 by seojyang          #+#    #+#             */
/*   Updated: 2022/11/19 13:59:28 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_util.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1);
	str = (char *)malloc(len + 1);
	if (str)
		ft_strlcpy(str, s1, len + 1);
	return (str);
}

char	*ft_chardup(char c)
{
	char	*str;

	str = (char *)malloc(2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	if ((char) c == '\0')
		return ((char *) s + ft_strlen(s));
	tmp = (char *) s;
	while (*tmp)
	{
		if ((unsigned char) *tmp == (unsigned char) c)
			return (tmp);
		tmp++;
	}
	return (0);
}

char	*ft_strjoin(const char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(s1_len + s2_len + 1);
	if (!str)
		return (0);
	ft_memcpy(str, s1, s1_len);
	ft_memcpy(str + s1_len, s2, s2_len + 1);
	free(s2);
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	n;

	n = 0;
	while (n + 1 < dstsize && src[n])
	{
		dst[n] = src[n];
		n++;
	}
	if (dstsize != 0)
		dst[n] = '\0';
	return (ft_strlen(src));
}
