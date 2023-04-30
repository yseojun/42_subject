/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:23:26 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/05 08:43:02 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_good(char *queen_y, int now_x)
{
	int	back_x;

	back_x = 0;
	while (back_x < now_x)
	{
		if (queen_y[back_x] == queen_y[now_x])
			return (0);
		else if (now_x - back_x == queen_y[now_x] - queen_y[back_x]
			|| now_x - back_x == queen_y[back_x] - queen_y[now_x])
			return (0);
		back_x++;
	}
	return (1);
}

void	put_q(char *queen_y, int x, int *count)
{
	int	y;

	if (x == 10)
	{
		write(1, queen_y, 11);
		(*count)++;
		return ;
	}
	y = 0;
	while (y < 10)
	{
		queen_y[x] = y + '0';
		if (is_good(queen_y, x) == 1)
			put_q(queen_y, x + 1, count);
		y++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	queen_y[11];
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (i < 11)
		queen_y[i++] = '0';
	queen_y[10] = '\n';
	put_q(queen_y, 0, &count);
	return (count);
}
