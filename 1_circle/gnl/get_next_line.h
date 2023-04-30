/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:15:45 by seojyang          #+#    #+#             */
/*   Updated: 2022/11/24 22:54:56 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_line
{
	char		*buffer;
	ssize_t		read_idx;
	ssize_t		read_max_len;
	ssize_t		output_len;
}	t_line;

char	*get_next_line(int fd);
char	*join(char *output, t_line *line);
char	*read_finish(t_line *line, char *output);

void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif