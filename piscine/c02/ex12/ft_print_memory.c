/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:44:06 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/03 12:12:47 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	prt_adr_hex(void *addr)
{
	intptr_t		num;
	unsigned int	n;
	char			*hex;
	char			adrr[16];

	num = (intptr_t)addr;
	n = 0;
	hex = "0123456789abcdef";
	while (n < 16)
	{
		adrr[15 - n] = hex[num % 16];
		num /= 16;
		n++;
	}
	write(1, adrr, 16);
	write(1, ": ", 2);
}

void	prt_cont_hex(unsigned char *addr, unsigned int r)
{
	unsigned int	n;
	char			*hex;

	hex = "0123456789abcdef";
	n = 0;
	while (n < 16)
	{
		if (n + 1 > r)
			write(1, "  ", 2);
		else
		{
			write(1, &hex[addr[n] / 16], 1);
			write(1, &hex[addr[n] % 16], 1);
		}
		if (n % 2 == 1)
			write(1, " ", 1);
		n++;
	}
}

void	prt_cont(char *str, unsigned int r)
{
	unsigned int	n;

	n = 0;
	while (n < 16)
	{
		if (n + 1 > r)
			break ;
		if (str[n] < 32 || 126 < str[n])
			write(1, ".", 1);
		else
			write(1, &str[n], 1);
		n++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	l;
	int				r;

	l = 0;
	r = size;
	if (!size)
		return (addr);
	while (r > 0)
	{
		prt_adr_hex(addr + l);
		prt_cont_hex(addr + l, r);
		prt_cont(addr + l, r);
		write(1, "\n", 1);
		l += 16;
		r -= 16;
	}
	return (addr);
}
