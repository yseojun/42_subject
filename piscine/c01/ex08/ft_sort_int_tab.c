/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 21:42:12 by seojyang          #+#    #+#             */
/*   Updated: 2022/09/29 16:53:21 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	n;
	int	tmp;

	n = 0;
	while (n < size - 1)
	{
		if (tab[n] > tab[n + 1])
		{
			tmp = tab[n];
			tab[n] = tab[n + 1];
			tab[n + 1] = tmp;
			n = -1;
		}
		n++;
	}
}
