/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:15:33 by seojyang          #+#    #+#             */
/*   Updated: 2023/01/17 17:01:32 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_line	line = {0, 0, 0, 0};
	char			*output;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	output = 0;
	line.output_len = 0;
	if (!line.buffer)
		line.buffer = malloc(BUFFER_SIZE);
	while (1)
	{
		if (line.read_idx == line.read_max_len)
		{
			line.read_idx = 0;
			line.read_max_len = read(fd, line.buffer, BUFFER_SIZE);
		}
		if (line.read_max_len <= 0)
			return (read_finish(&line, output));
		output = join(output, &line);
		if (!output)
			return (read_finish(&line, output));
		if (line.output_len && *(output + line.output_len - 1) == '\n')
			return (output);
	}
}
