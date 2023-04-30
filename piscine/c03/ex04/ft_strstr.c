/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:10:17 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/03 16:22:02 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char *str)
{
	int	n;

	n = 0;
	while (*(str++))
		n++;
	return (n);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	n;
	int	t;
	int	i;

	n = 0;
	i = 0;
	t = str_len(to_find);
	if (!t)
		return (str);
	while (str[n])
	{
		i = 0;
		while (i < t)
		{
			if (str[n + i] == to_find[i])
				i++;
			else
				break ;
			if (i == t)
				return (str + n);
		}
		n++;
	}
	return (0);
}
