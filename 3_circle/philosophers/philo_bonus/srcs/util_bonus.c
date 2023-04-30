/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:50:05 by seojyang          #+#    #+#             */
/*   Updated: 2023/04/30 14:10:45 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

static char	*get_action_str(int action)
{
	if (action == FORKN)
		return (FORK);
	else if (action == EATN)
		return (EAT);
	else if (action == SLEEPN)
		return (SLEEP);
	else if (action == THINKN)
		return (THINK);
	else
		return (DIE);
}

void	print_line(t_info *info, int action)
{
	printf("%lld %d %s", get_dt(info->start_time), info->num, \
		get_action_str(action));
}

static size_t	chk_len(long long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*output;
	size_t		len;
	long long	num;

	num = n;
	len = chk_len(num);
	output = (char *)malloc(len + 1);
	if (output)
	{
		output[len] = '\0';
		if (num < 0)
		{
			output[0] = '-';
			num = -num;
		}
		if (num == 0)
			output[0] = '0';
		while (len-- > 0 && num)
		{
			output[len] = num % 10 + '0';
			num /= 10;
		}
	}
	return (output);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(s1_len + s2_len + 1);
	if (!str)
		return (0);
	ft_memcpy(str, s1, s1_len);
	ft_memcpy(str + s1_len, s2, s2_len + 1);
	return (str);
}
