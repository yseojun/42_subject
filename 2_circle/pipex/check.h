/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:20:06 by seojyang          #+#    #+#             */
/*   Updated: 2023/02/01 14:51:35 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include "libft/libft.h"
# include "fcntl.h"
# include "unistd.h"
# include "stdlib.h"
# include <stdio.h>

int		infile_chk(char *infile);
int		outfile_chk(char *outfile);
void	perror_exit(char *name);

#endif