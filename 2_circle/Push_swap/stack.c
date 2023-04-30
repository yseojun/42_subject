/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:21:07 by seojyang          #+#    #+#             */
/*   Updated: 2023/01/29 17:12:43 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "check.h"

t_list	*make_list(int ac, char **av)
{
	t_list	*new_list;
	t_elem	*new_elem;
	int		idx;

	new_list = ft_lstnew('a');
	idx = 1;
	while (idx < ac)
	{
		if (!is_digit(av[idx]))
			make_for_multiple_av(av[idx], new_list);
		else
		{
			new_elem = (t_elem *)malloc(sizeof(t_elem));
			new_elem->data = ft_atoi(av[idx]);
			new_elem->next = 0;
			new_elem->prev = 0;
			chk_double(&new_list, new_elem);
			ft_lstadd_back(&new_list, new_elem);
			new_list->size++;
		}
		idx++;
	}
	return (new_list);
}

t_elem	*pophead(t_list *list)
{
	t_elem	*ball;

	ball = list->head;
	if (ball->next)
		ball->next->prev = 0;
	list->head = ball->next;
	if (list->last == ball)
		list->last = 0;
	ball->next = 0;
	ball->prev = 0;
	return (ball);
}

t_elem	*poplast(t_list *list)
{
	t_elem	*ball;

	ball = list->last;
	if (ball->prev)
		ball->prev->next = 0;
	list->last = ball->prev;
	if (list->head == ball)
		list->head = 0;
	ball->next = 0;
	ball->prev = 0;
	return (ball);
}

void	add_back_of_head(t_list *list, t_elem *moving)
{
	t_elem	*head;

	head = list->head;
	if (head->next)
	{
		head->next->prev = moving;
		moving->next = head->next;
	}
	head->next = moving;
	moving->prev = head;
	if (!list->head->next->next)
		list->last = list->head->next;
}

void	error_fin(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}
