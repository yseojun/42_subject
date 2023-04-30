/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:30:43 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/11 21:43:22 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		n;
	char	*tmp;
	int		length;

	n = 0;
	while (tab[n])
		n++;
	length = n;
	n = 0;
	while (n + 1 < length)
	{
		if (cmp(tab[n], tab[n + 1]) > 0)
		{
			tmp = tab[n];
			tab[n] = tab[n + 1];
			tab[n + 1] = tmp;
			n = -1;
		}
		n++;
	}
}
