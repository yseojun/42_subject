/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:07:36 by seojyang          #+#    #+#             */
/*   Updated: 2023/02/07 17:27:08 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_BONUS_H
# define UTIL_BONUS_H

# include <unistd.h>
# include "../libft/libft.h"

void	free_arr(void **arr);
int		is_digit(char *str);
int		is_color(char *str);
int		atohex(char *str);
int		is_hex(char c);

#endif