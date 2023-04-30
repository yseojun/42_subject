/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:12:27 by seojyang          #+#    #+#             */
/*   Updated: 2022/12/30 19:58:53 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_elem	*search;
	t_elem	*save;

	if (!lst)
		return ;
	search = (*lst)->head;
	while (search)
	{
		save = search->next;
		ft_lstdelone(search, del);
		search = save;
	}
	*lst = 0;
}
