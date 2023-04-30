/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:56:33 by seojyang          #+#    #+#             */
/*   Updated: 2022/12/31 13:28:02 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_elem *new)
{
	t_elem	*last;

	if (!new)
		return ;
	last = ft_lstlast(*lst);
	if (!last)
		(*lst)->head = new;
	else
	{
		new->prev = last;
		last->next = new;
	}
	(*lst)->last = new;
}
