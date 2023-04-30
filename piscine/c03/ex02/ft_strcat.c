/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:51:32 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/02 12:29:49 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	n;
	int	m;

	n = 0;
	m = 0;
	while (dest[n])
		n++;
	while (src[m])
	{
		dest[n + m] = src[m];
		m++;
	}
	dest[n + m] = '\0';
	return (dest);
}
