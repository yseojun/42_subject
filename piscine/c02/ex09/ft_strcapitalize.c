/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:27:00 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/01 15:46:28 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_up_(char c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	return (0);
}

int	is_low_(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}

int	is_word_(char c)
{
	if (is_low_(c) || ('0' <= c && c <= '9'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	n;
	int	flag;

	n = 0;
	flag = 1;
	while (str[n])
	{
		if (is_up_(str[n]))
			str[n] += 32;
		n++;
	}
	n = 0;
	while (str[n])
	{
		if (is_word_(str[n]))
		{
			if (is_low_(str[n]) && flag)
				str[n] -= 32;
			flag = 0;
		}
		else if (!is_word_(str[n]))
			flag = 1;
		n++;
	}
	return (str);
}
