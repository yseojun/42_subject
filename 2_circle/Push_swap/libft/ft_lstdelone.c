/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:01:46 by seojyang          #+#    #+#             */
/*   Updated: 2022/12/31 12:59:26 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_elem *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del)
		del(&lst->data);
	free(lst);
}
