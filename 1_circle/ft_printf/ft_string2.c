/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:18:14 by seojyang          #+#    #+#             */
/*   Updated: 2022/11/19 13:59:26 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_util.h"

char	*ft_strtrim(char *s1, char const *set)
{
	char	*tmp;
	size_t	s1_len;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (0);
	s1_len = ft_strlen(s1);
	start = 0;
	end = 0;
	if (s1_len)
	{
		while (start <= s1_len && ft_strchr(set, s1[start]))
			start++;
		if (s1_len + 1 == start)
			start--;
		while (start != s1_len && ft_strchr(set, s1[s1_len - 1 - end]))
			end++;
	}
	tmp = (char *)malloc(s1_len - start - end + 1);
	if (tmp)
		ft_strlcpy(tmp, s1 + start, s1_len - start - end + 1);
	free(s1);
	return (tmp);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 32);
	else
		return (c);
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}
