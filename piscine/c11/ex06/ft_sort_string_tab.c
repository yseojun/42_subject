/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:30:07 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/11 21:42:40 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	n;

	n = 0;
	while (s1[n] || s2[n])
	{
		if (s1[n] != s2[n])
			break ;
		n++;
	}
	return ((unsigned char)s1[n] - (unsigned char)s2[n]);
}

void	ft_sort_string_tab(char **tab)
{
	int		n;
	int		length;
	char	*tmp;

	n = 0;
	while (tab[n])
		n++;
	length = n;
	n = 0;
	while (n + 1 < length)
	{
		if (ft_strcmp(tab[n], tab[n + 1]) > 0)
		{
			tmp = tab[n];
			tab[n] = tab[n + 1];
			tab[n + 1] = tmp;
			n = -1;
		}
		n++;
	}
}
