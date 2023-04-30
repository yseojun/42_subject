/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:48:00 by seojyang          #+#    #+#             */
/*   Updated: 2023/01/17 17:51:47 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include "struct.h"

int		is_digit(char *str);
void	check_av(int ac, char **av);
void	chk_double(t_list **list, t_elem *new);
void	make_for_multiple_av(char *av, t_list *new_list);
int		is_sorted(t_list *a);

#endif