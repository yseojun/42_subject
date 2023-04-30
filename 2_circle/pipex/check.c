/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:21:24 by seojyang          #+#    #+#             */
/*   Updated: 2023/02/19 19:38:43 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

int	infile_chk(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("pipex: ", 2);
		perror_exit(infile);
	}
	return (fd);
}

int	outfile_chk(char *outfile)
{
	int	fd;

	fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		ft_putstr_fd("pipex: ", 2);
		perror_exit(outfile);
	}
	return (fd);
}
