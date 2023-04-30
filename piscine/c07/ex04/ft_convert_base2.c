/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:19:40 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/05 19:41:43 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_base(char c, char *base)
{
	int	n;

	n = 0;
	while (base[n])
	{
		if (base[n] == c)
			return (n);
		n++;
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (*(str++))
		n++;
	return (n);
}
