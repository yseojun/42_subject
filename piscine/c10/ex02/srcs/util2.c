/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:45:01 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/19 15:24:13 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

int	is_c_option(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	if (n != 2)
		return (0);
	if (str[0] == '-' && str[1] == 'c')
		return (1);
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest);
}

int	ft_atoi(char *str)
{
	int	ans;
	int	i;

	i = 0;
	ans = 0;
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (-1);
		ans = ans * 10 + str[i] - '0';
		i++;
	}
	return (ans);
}
