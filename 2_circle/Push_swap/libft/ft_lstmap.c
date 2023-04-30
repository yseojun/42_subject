/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:24:02 by seojyang          #+#    #+#             */
/*   Updated: 2022/12/31 21:27:37 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_elem	*new_elem;
	t_elem	*search;

	if (!lst || !f || !del)
		return (0);
	search = lst->head;
	new_list = 0;
	while (search)
	{
		new_elem = ft_lstnew(0)->head;
		if (!new_elem)
		{
			ft_lstclear(&new_list, del);
			return (new_list);
		}
		ft_lstadd_back(&new_list, new_elem);
		search = search->next;
	}
	return (new_list);
}
