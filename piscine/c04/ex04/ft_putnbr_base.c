/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:19:14 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/03 19:21:18 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	chk_base(char *base)
{
	int	n;
	int	only_one[256];

	n = 0;
	while (n < 256)
		only_one[n++] = 0;
	n = 0;
	while (base[n])
	{
		only_one[(unsigned char)base[n]]++;
		if (only_one[(unsigned char)base[n]] == 2)
			return (-1);
		else if (base[n] == '+' || base[n] == '-')
			return (-1);
		n++;
	}
	return (n);
}

void	put_base(long long num, char *base, int basel)
{
	if (!num)
		return ;
	put_base(num / basel, base, basel);
	write(1, &base[num % basel], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			basel;
	long long	num;

	basel = chk_base(base);
	if (basel <= 1)
		return ;
	num = nbr;
	if (!num)
		write(1, &base[0], 1);
	else if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	put_base(num, base, basel);
}
