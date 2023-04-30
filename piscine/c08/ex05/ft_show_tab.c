/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:42:02 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/10 16:49:39 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	write(1, str, n);
}

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
		write(1, "0", 1);
	else if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	putput(nb);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	n;

	n = 0;
	while (par[n].str)
	{
		ft_putstr(par[n].str);
		write(1, "\n", 1);
		ft_putnbr(par[n].size);
		write(1, "\n", 1);
		ft_putstr(par[n].copy);
		write(1, "\n", 1);
		n++;
	}
}
