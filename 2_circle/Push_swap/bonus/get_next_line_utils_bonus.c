/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:16:18 by seojyang          #+#    #+#             */
/*   Updated: 2023/01/17 17:01:36 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*join(char *output, t_line *line)
{
	char	*new;
	ssize_t	join_len;

	join_len = 0;
	while (line->read_idx + join_len < line->read_max_len)
	{
		if (*(line->buffer + line->read_idx + join_len) == '\n')
		{
			join_len++;
			break ;
		}
		join_len++;
	}
	new = malloc(line->output_len + join_len + 1);
	if (!new)
		return (0);
	ft_memcpy(new, output, line->output_len);
	ft_memcpy(new + line->output_len, line->buffer + line->read_idx, join_len);
	new[line->output_len + join_len] = 0;
	line->output_len += join_len;
	line->read_idx += join_len;
	free(output);
	return (new);
}

char	*read_finish(t_line *line, char *output)
{
	if (line->read_max_len < 0)
	{
		if (output)
			free(output);
		output = 0;
		line->read_idx = 0;
		line->read_max_len = 0;
	}
	free(line->buffer);
	line->buffer = 0;
	return (output);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	idx;

	if (!dst && !src)
		return (0);
	idx = 0;
	while (idx < n)
	{
		*((unsigned char *) dst + idx) = *((unsigned char *) src + idx);
		idx++;
	}
	return (dst);
}
