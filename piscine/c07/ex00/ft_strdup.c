/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:18:07 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/05 21:11:21 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		n;
	char	*str;

	n = 0;
	while (src[n])
		n++;
	str = (char *)malloc((sizeof(char) * n));
	if (!str)
		return (0);
	n = 0;
	while (src[n])
	{
		str[n] = src[n];
		n++;
	}
	str[n] = '\0';
	return (str);
}
/*
#include <stdio.h>
int main ()
{
	printf("%s", ft_strdup("dldl"));
}
*/
