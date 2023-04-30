/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:28:23 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/01 15:45:58 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_loww(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}

char	*ft_strupcase(char *str)
{
	int	n;

	n = 0;
	while (str[n])
	{
		if (is_loww(str[n]))
			str[n] -= 32;
		n++;
	}
	return (str);
}
