/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:29:03 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/11 21:54:25 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	n;
	int	count;

	n = 0;
	count = 0;
	while (n < length)
	{
		if (f(tab[n]) != 0)
			count++;
		n++;
	}
	return (count);
}
