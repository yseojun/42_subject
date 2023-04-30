/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:17:41 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/20 21:52:40 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "util.h"
#include "f_string.h"

void	print_addr(long long addr, int is_c)
{
	int		n;
	char	*hex;
	char	output[8];

	hex = "0123456789abcdef";
	n = 0;
	while (n < 8)
	{
		output[7 - n] = hex[addr % 16];
		addr /= 16;
		n++;
	}
	if (!is_c)
		write(1, output + 1, 7);
	else
		write(1, output, 8);
	write(1, " ", 1);
	if (is_c)
		write(1, " ", 1);
}

void	print_ascii(char *str, int size, int is_c)
{
	const char	*hex = "0123456789abcdef";
	int			n;

	n = -1;
	while (++n < size)
	{
		write(1, &hex[(unsigned char)*str / 16], 1);
		write(1, &hex[(unsigned char)*str++ % 16], 1);
		write(1, " ", 1);
		if (n == 15 && !is_c)
			write(1, " ", 1);
		if (is_c && (n == 7 || n == 15))
			write(1, " ", 1);
	}
	--n;
	while (++n < 16)
	{
		write(1, "   ", 3);
		if (n == 15 && !is_c)
			write(1, " ", 1);
		if (is_c && (n == 7 || n == 15))
			write(1, " ", 1);
	}
	if (!is_c)
		write(1, "\n", 1);
}

void	print_content(char *str, int size)
{
	int	n;

	n = 0;
	write(1, "|", 1);
	while (n < size)
	{
		if (str[n] < 32 || 126 < str[n])
			write(1, ".", 1);
		else
			write(1, &str[n], 1);
		n++;
	}
	write(1, "|\n", 2);
}

void	final(char *remain, long long addr, char **av, int ac)
{
	if (addr)
	{
		if (remain)
		{
			if (ac >= 2)
				print_final(remain, addr, is_c_option(av[1]));
			else
				print_final(remain, addr, 0);
		}
	}
}

void	print_final(char *remain, long long addr, int is_c)
{
	int	size;

	size = ft_strlen(remain);
	if (size)
	{
		print_addr(addr, is_c);
		print_ascii(remain, size, is_c);
		if (is_c)
			print_content(remain, size);
	}
	print_final_addr(addr + size, is_c);
	write(1, "\n", 1);
}
