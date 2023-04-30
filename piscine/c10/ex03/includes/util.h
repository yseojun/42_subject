/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:02:32 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/20 21:49:45 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <stdlib.h>
# include <unistd.h>
# include <libgen.h>
# include <sys/errno.h>
# include <string.h>

char	*read_content(char **remain, int fd);
int		is_c_option(char *str);
void	hexdump_errno(char **av, int n);
void	print_final_addr(long long addr, int is_c);

#endif
