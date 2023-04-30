/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:20:06 by seojyang          #+#    #+#             */
/*   Updated: 2023/01/31 20:10:22 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_BONUS_H
# define CHECK_BONUS_H

# include "fcntl.h"
# include "unistd.h"
# include "stdlib.h"
# include "info_bonus.h"
# include <stdio.h>

int		heredoc_chk(char *av1);
int		make_heredoc(t_info *info);

int		infile_chk(char *infile);
int		outfile_chk(char *outfile, t_info *info);
void	perror_exit(char *name);

#endif