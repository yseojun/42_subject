/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:35:23 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/07 19:24:07 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	chk_base2(char *base)
{
	int	n;
	int	only_one[256];

	n = 0;
	while (n < 256)
		only_one[n++] = 0;
	n = 0;
	while (base[n])
	{
		if (only_one[(unsigned char)base[n]])
			return (-1);
		else if (base[n] == '+' || base[n] == '-' || base[n] == ' '
			|| (9 <= base[n] && base[n] <= 13))
			return (-1);
		only_one[(unsigned char)base[n]]++;
		n++;
	}
	return (n);
}

int	is_base(char c, char *base)
{
	int	n;

	n = 0;
	while (base[n])
	{
		if (base[n] == c)
			return (n);
		n++;
	}
	return (-1);
}

int	atoi_base(char *str, char *base, int basel)
{
	int	d;
	int	n;
	int	ans;

	d = 1;
	n = 0;
	ans = 0;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			d = -d;
		str++;
	}
	while (*str)
	{
		n = is_base(*(str++), base);
		if (n < 0)
			return (ans * d);
		ans = ans * basel + n;
	}
	return (ans * d);
}

int	ft_atoi_base(char *str, char *base)
{
	int	basel;

	basel = chk_base2(base);
	if (basel <= 1)
		return (0);
	return (atoi_base(str, base, basel));
}
