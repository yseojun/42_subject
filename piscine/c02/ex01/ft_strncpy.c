/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:35:48 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/01 13:45:45 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	m;

	m = 0;
	while (m < n && src[m])
	{
		dest[m] = src[m];
		m++;
	}
	while (m < n)
		dest[m++] = '\0';
	return (dest);
}
