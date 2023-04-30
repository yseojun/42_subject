/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:06:22 by seojyang          #+#    #+#             */
/*   Updated: 2022/09/29 11:04:37 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int			i;
	char		numc[10];
	long long	num;

	i = 0;
	num = nb;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	else if (num == 0)
		write(1, "0", 1);
	while (num)
	{
		numc[i++] = num % 10 + '0';
		num /= 10;
	}
	i--;
	while (i >= 0)
		write(1, &numc[i--], 1);
}
