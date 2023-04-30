/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:19:27 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/08 11:52:58 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	is_base(char c, char *base);
int	ft_strlen(char *str);

int	chk_base(char *base)
{
	int	n;
	int	only_one[256];

	if (!base)
		return (0);
	n = 0;
	while (n < 256)
		only_one[n++] = 0;
	n = 0;
	while (base[n])
	{
		if (only_one[(unsigned char)base[n]]
			|| base[n] == '+' || base[n] == '-' || base[n] == ' '
			|| (9 <= base[n] && base[n] <= 13))
			return (0);
		only_one[(unsigned char)base[n]]++;
		n++;
	}
	if (n < 2)
		return (0);
	return (1);
}

int	chk_size(int num, char *base_to)
{
	int	size;
	int	basel;

	size = 0;
	if (!num)
		return (2);
	basel = ft_strlen(base_to);
	if (num < 0)
		size++;
	while (num)
	{
		num /= basel;
		size++;
	}
	return (size + 1);
}

long long	ft_atoi(char *str, char *base)
{
	int	ans;
	int	sign;
	int	n;
	int	basel;

	basel = ft_strlen(base);
	ans = 0;
	sign = 1;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str)
	{
		n = is_base(*(str++), base);
		if (n < 0)
			return (ans * sign);
		ans = ans * basel + n;
	}
	return (ans * sign);
}

char	*ft_itoa(long long num, char *base_to)
{
	char		*to_make;
	long long	basel;
	int			size;

	size = chk_size(num, base_to);
	basel = ft_strlen(base_to);
	to_make = (char *)malloc(sizeof(char) * size);
	if (!to_make)
		return (0);
	to_make[--size] = '\0';
	if (num == 0)
		to_make[0] = base_to[0];
	else if (num < 0)
	{
		to_make[0] = '-';
		num = -num;
	}
	while (num)
	{
		to_make[--size] = base_to[num % basel];
		num /= basel;
	}
	return (to_make);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (!chk_base(base_from) || !chk_base(base_to))
		return (0);
	return (ft_itoa(ft_atoi(nbr, base_from), base_to));
}
/*
#include <stdio.h>
int main()
{
	char *str;
	char *base1;
	char *base2;

	str = "     ---+--2147483647";
	base1 = "0123456789";
	base2 = "0123456789abcdef";
	printf("%s", ft_convert_base(str, base1, base2));
	return (0);
}
*/
