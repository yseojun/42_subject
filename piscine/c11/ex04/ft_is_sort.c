/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:29:19 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/12 00:24:07 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	n;

	n = 0;
	if (length <= 2)
		return (1);
	if (f(tab[n], tab[length - 1]) > 0)
	{
		while (n + 1 < length && f(tab[n], tab[n + 1]) >= 0)
			n++;
	}
	else if (f(tab[n], tab[length - 1]) < 0)
	{
		while (n + 1 < length && f(tab[n], tab[n + 1]) <= 0)
			n++;
	}
	else
	{
		while (n + 1 < length && f(tab[n], tab[n + 1]) == 0)
			n++;
	}
	if (n != length - 1)
		return (0);
	return (1);
}
