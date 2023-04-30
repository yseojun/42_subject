/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:05:50 by seojyang          #+#    #+#             */
/*   Updated: 2022/09/29 10:57:18 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	sep_num(int n)
{
	char	num1;
	char	num2;

	num1 = n / 10 + 48;
	num2 = n % 10 + 48;
	write(1, &num1, 1);
	write(1, &num2, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			sep_num(a);
			write(1, " ", 1);
			sep_num(b);
			if (a == 98)
				return ;
			write(1, ", ", 2);
			b++;
		}
		a++;
	}
}
