/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:37:40 by seojyang          #+#    #+#             */
/*   Updated: 2022/12/31 15:31:20 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_elem *new)
{
	if (!new)
		return ;
	new->next = (*lst)->head;
	(*lst)->head = new;
	if (new->next == 0)
		(*lst)->last = new;
	else
		new->next->prev = new;
}
