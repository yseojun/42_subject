/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:33:45 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/20 17:13:01 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_list_size(t_list *begin_list)
{
	int		n;
	t_list	*search;

	search = begin_list;
	n = 0;
	while (search)
	{
		search = search->next;
