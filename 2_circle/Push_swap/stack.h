/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:26:04 by seojyang          #+#    #+#             */
/*   Updated: 2023/01/29 17:14:14 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft/libft.h"

typedef struct s_stacks
{
	struct s_list	*a;
	struct s_list	*b;
}	t_stacks;

t_list	*make_list(int ac, char **av);
t_elem	*pophead(t_list *list);
t_elem	*poplast(t_list *list);
void	add_back_of_head(t_list *list, t_elem *elem);
void	error_fin(void);

#endif