/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:28:08 by seojyang          #+#    #+#             */
/*   Updated: 2022/09/28 19:06:31 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	prt_num(char *num, int m)
{
	write(1, num, m);
	if (num[0] == 10 - m + '0')
		return ;
	write(1, ", ", 2);
}

void	make_num(int n, int m, int d, char *num)
{
	if (m == n)
	{
		prt_num(num, m);
		return ;
	}
	while (d < 10)
	{
		num[m] = d + '0';
		make_num(n, m + 1, d + 1, num);
		d++;
	}
}

void	ft_print_combn(int n)
{
	char	num[10];

	make_num(n, 0, 0, num);
}
