/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:34:29 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/19 22:14:37 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <unistd.h>

void	print_addr(long long addr, int is_c);
void	print_ascii(char *str, int size, int is_c);
void	print_content(char *str, int size);
void	final(char *remain, long long addr, char **av, int ac);
void	print_final(char *remain, long long addr, int is_c);

#endif
