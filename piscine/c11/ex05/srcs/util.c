/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:48:35 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/11 19:20:37 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	d;
	int	ans;

	d = 1;
	ans = 0;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			d = -d;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		ans = ans * 10 + *str - '0';
		str++;
	}
	return (ans * d);
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
