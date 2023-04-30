/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 21:39:46 by seojyang          #+#    #+#             */
/*   Updated: 2022/09/29 16:51:53 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	n;
	int	tmp;

	n = 0;
	while (n < size / 2)
	{
		tmp = tab[n];
		tab[n] = tab[size - n - 1];
		tab[size - n - 1] = tmp;
		n++;
	}
}
