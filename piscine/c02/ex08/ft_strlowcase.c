/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:32:48 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/01 15:46:14 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_upp(char c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	return (0);
}

char	*ft_strlowcase(char *str)
{
	int	n;

	n = 0;
	while (str[n])
	{
		if (is_upp(str[n]))
			str[n] += 32;
		n++;
	}
	return (str);
}
