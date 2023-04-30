/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:11:23 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/19 22:12:33 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	idx;

	idx = 0;
	while (s1[idx] && s2[idx] && idx < n)
	{
		if (s1[idx] != s2[idx])
			break ;
		idx++;
	}
	return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
}

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (*str++)
		n++;
	return (n);
}

char	*ft_strcat(char *dest, char *src)
{
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest);
}

char	*ft_newstr(char *s1, char *s2)
{
	char	*new;
	int		size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = (char *)malloc(sizeof(char) * size);
	if (!new)
		return (0);
	new[0] = '\0';
	ft_strcat(new, s1);
	ft_strcat(new, s2);
	free(s1);
	free(s2);
	return (new);
}

char	*ft_strdup(char *s1)
{
	int		len;
	char	*new;

	len = 0;
	while (s1[len])
		len++;
	new = (char *)malloc(sizeof(char) * (len + 1));
	while (*s1)
		*new++ = *s1++;
	*new = '\0';
	return (new);
}
