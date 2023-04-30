/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:47:20 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/03 19:35:28 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putput(int n)
{
	char	c;

	if (!n)
		return ;
	putput(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (!nb)
	{
		write(1, "0", 1);
		return ;
	}
	else if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	putput(nb);
}
