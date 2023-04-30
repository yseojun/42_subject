/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:46:44 by seojyang          #+#    #+#             */
/*   Updated: 2023/01/29 18:06:05 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "stack.h"

#define INT_MAX 2147483647
#define INT_MIN -2147483648

int	is_digit(char *str)
{
	int			idx;
	long long	ans;

	idx = 0;
	ans = 0;
	while ((9 <= str[idx] && str[idx] <= 13) || str[idx] == 32)
		idx++;
	if (str[idx] == '-' || str[idx] == '+')
		idx++;
	while (str[idx])
	{
		if (!ft_isdigit(str[idx]))
			return (0);
		ans = ans * 10 + str[idx] - '0';
		if (ans > INT_MAX && !(ans == -INT_MIN && str[0] == '-'))
			return (0);
		idx++;
	}
	if (idx == 0)
		return (0);
	idx--;
	if ((str[idx] == ' ' || str[idx] == '+' || str[idx] == '-'))
		return (0);
	else
		return (1);
}

void	check_av(int ac, char **av)
{
	int		idx;
	int		chk_idx;
	char	**chk;

	idx = 1;
	while (idx < ac)
	{
		if (!is_digit(av[idx]))
		{
			chk = ft_split(av[idx], ' ');
			chk_idx = 0;
			while (chk[chk_idx])
			{
				if (!is_digit(chk[chk_idx]))
					error_fin();
				free(chk[chk_idx++]);
			}
			free(chk);
		}
		idx++;
	}
}

void	chk_double(t_list **list, t_elem *new)
{
	t_elem	*search;

	search = (*list)->head;
	while (search)
	{
		if (new->data == search->data)
		{
			ft_lstclear(list, 0);
			free(new);
			ft_putendl_fd("Error", 2);
			exit(1);
		}
		search = search->next;
	}
}

void	make_for_multiple_av(char *av, t_list *new_list)
{
	char	**tmp;
	int		idx;
	t_elem	*new_elem;

	tmp = ft_split(av, ' ');
	idx = 0;
	while (tmp[idx])
	{
		new_elem = (t_elem *)malloc(sizeof(t_elem));
		new_elem->data = ft_atoi(tmp[idx]);
		free(tmp[idx++]);
		new_elem->next = 0;
		new_elem->prev = 0;
		chk_double(&new_list, new_elem);
		ft_lstadd_back(&new_list, new_elem);
		new_list->size++;
	}
	free(tmp);
}

int	is_sorted(t_list *a)
{
	t_elem	*search;
	int		tmp;

	search = a->head;
	tmp = a->head->data;
	search = search->next;
	while (search)
	{
		if (tmp > search->data)
			return (0);
		tmp = search->data;
		search = search->next;
	}
	return (1);
}
