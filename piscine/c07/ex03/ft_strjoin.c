/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:18:46 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/07 23:49:52 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	cal_lenn(int size, char **strs, char *sep)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (size == 0)
		return (0);
	while (i < size && strs[i])
		len += ft_strlen(strs[i++]);
	len += ft_strlen(sep) * (size - 1);
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		n;
	int		j_idx;
	int		idx;
	char	*join;

	join = (char *)malloc(sizeof(char) * (cal_lenn(size, strs, sep) + 1));
	if (!join)
		return (0);
	n = 0;
	j_idx = 0;
	while (n < size && strs[n])
	{
		idx = 0;
		while (strs[n][idx])
			join[j_idx++] = strs[n][idx++];
		idx = 0;
		if (n != size - 1)
		{
			while (sep[idx])
				join[j_idx++] = sep[idx++];
		}
		n++;
	}
	join[j_idx] = '\0';
	return (join);
}
/*
#include <stdio.h>
int	main()
{
	char *strs[2];
	char *sep;

	sep = ":";
	strs[0] = "123";
	strs[1] = "456";
	printf("%s", ft_strjoin(2, strs, sep));
}
*/
