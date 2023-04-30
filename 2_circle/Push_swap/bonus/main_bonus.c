/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:10:28 by seojyang          #+#    #+#             */
/*   Updated: 2023/01/29 17:55:38 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"
#include "get_next_line_bonus.h"

int		chk_op(t_stacks *s);
int		chk_op_valid(char *op, size_t op_len);
void	run_op(int op, t_stacks *s);

int	main(int ac, char **av)
{
	t_list		*a;
	t_list		*b;
	t_stacks	s;

	if (ac < 2)
		return (0);
	check_av(ac, av);
	a = make_list(ac, av);
	if (!a->size)
		exit(0);
	b = ft_lstnew('b');
	s.a = a;
	s.b = b;
	if (!chk_op(&s))
		ft_putendl_fd("Error", 2);
	else
	{
		if (!b->size && is_sorted(a))
			ft_putendl_fd("OK", 1);
		else
			ft_putendl_fd("KO", 1);
	}
	ft_lstclear(&a, 0);
	ft_lstclear(&b, 0);
	return (0);
}

int	chk_op(t_stacks *s)
{
	char	*op_chr;
	int		op;

	while (1)
	{
		op_chr = get_next_line(0);
		if (!op_chr)
			break ;
		op = chk_op_valid(op_chr, ft_strlen(op_chr));
		free(op_chr);
		if (op < 0)
			return (0);
		run_op(op, s);
	}
	return (1);
}

int	chk_op_valid(char *op, size_t op_len)
{
	if (!ft_strncmp("pa\n", op, op_len))
		return (0);
	else if (!ft_strncmp("pb\n", op, op_len))
		return (1);
	else if (!ft_strncmp("sa\n", op, op_len))
		return (2);
	else if (!ft_strncmp("sb\n", op, op_len))
		return (3);
	else if (!ft_strncmp("ss\n", op, op_len))
		return (4);
	else if (!ft_strncmp("ra\n", op, op_len))
		return (5);
	else if (!ft_strncmp("rb\n", op, op_len))
		return (6);
	else if (!ft_strncmp("rra\n", op, op_len))
		return (8);
	else if (!ft_strncmp("rrb\n", op, op_len))
		return (9);
	else if (!ft_strncmp("rrr\n", op, op_len))
		return (10);
	else if (!ft_strncmp("rr\n", op, op_len))
		return (7);
	else
		return (-1);
}

void	run_op(int op, t_stacks *s)
{
	if (op == 0)
		pa(s);
	else if (op == 1)
		pb(s);
	else if (op == 2)
		sa(s);
	else if (op == 3)
		sb(s);
	else if (op == 4)
		ss(s);
	else if (op == 5)
		ra(s);
	else if (op == 6)
		rb(s);
	else if (op == 7)
		rr(s);
	else if (op == 8)
		rra(s);
	else if (op == 9)
		rrb(s);
	else if (op == 10)
		rrr(s);
}
