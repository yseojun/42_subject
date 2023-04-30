/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:54:13 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/11 19:20:10 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		cal_add(int a, int b);
int		cal_sub(int a, int b);
int		cal_div(int a, int b);
int		cal_dup(int a, int b);
int		cal_mod(int a, int b);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

int	chk_op(char *op)
{
	int	n;

	n = 0;
	while (op[n])
		n++;
	if (n != 1)
		return (-1);
	if (op[0] == '+')
		return (0);
	else if (op[0] == '-')
		return (1);
	else if (op[0] == '/')
		return (2);
	else if (op[0] == '*')
		return (3);
	else if (op[0] == '%')
		return (4);
	else
		return (-1);
}

int	cal_ab(int op, int a, int b)
{
	int	(*cal[5])(int, int);

	cal[0] = cal_add;
	cal[1] = cal_sub;
	cal[2] = cal_div;
	cal[3] = cal_dup;
	cal[4] = cal_mod;
	return (cal[op](a, b));
}

int	main(int ac, char **av)
{
	int	op;
	int	a;
	int	b;

	if (ac != 4)
		return (0);
	op = chk_op(av[2]);
	if (op < 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	a = ft_atoi(av[1]);
	b = ft_atoi(av[3]);
	if (op == 2 && b == 0)
		write(1, "Stop : division by zero\n", 24);
	else if (op == 4 && b == 0)
		write(1, "Stop : modulo by zero\n", 22);
	else
	{
		ft_putnbr(cal_ab(op, a, b));
		write(1, "\n", 1);
	}
	return (0);
}
