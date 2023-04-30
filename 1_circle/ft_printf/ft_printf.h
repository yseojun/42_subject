/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:40:04 by seojyang          #+#    #+#             */
/*   Updated: 2022/11/19 17:29:48 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

typedef struct s_info
{
	char	type;
	char	width_fill;
	char	front;
	int		is_left;
	int		is_hash;
	int		is_zero;
	int		is_precision;
	int		is_null;
	size_t	width;
	size_t	precision;
}			t_info;
int		ft_printf(const char *str, ...);
void	put_percent(const char *str, unsigned int *idx, va_list ap, int *len);
void	init_info(t_info *info);
void	make_info(const char *str, unsigned int *idx, t_info *info);
void	edit_info(t_info *info, char *arg);
size_t	make_size(const char *str, unsigned int *idx);
char	*make_arg(t_info info, va_list ap);
char	*edit_arg(t_info *info, va_list ap);
char	*make_hash(t_info *info, char *arg);
char	*combine_precision(t_info info, char *arg);
char	*make_for_string(t_info info, char *arg);
void	before_malloc_precision(t_info *info, char *arg, size_t *arg_len);
void	after_malloc_precision(t_info info, char **arg, \
							char **precision, size_t *arg_len);
char	*combine_width(t_info info, char *arg);
void	after_malloc_width(t_info info, char **arg, \
						char **width, size_t *arg_len);
void	print_arg(t_info info, int *len, char *arg);
char	*make_upper(char *arg);

#endif