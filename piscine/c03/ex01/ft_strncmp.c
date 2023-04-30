/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:46:39 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/02 12:30:33 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	m;

	m = 0;
	if (!n)
		return (0);
	while (m + 1 < n && s1[m] && s2[m])
	{
		if (s1[m] != s2[m])
			break ;
		m++;
	}
	return ((unsigned char)s1[m] - (unsigned char)s2[m]);
}
