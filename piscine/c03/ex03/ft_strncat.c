/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:04:34 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/02 19:10:03 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	n;
	unsigned int	m;

	n = 0;
	m = 0;
	while (dest[n])
		n++;
	while (src[m] && m < nb)
	{
		dest[n + m] = src[m];
		m++;
	}
	dest[n + m] = '\0';
	return (dest);
}
