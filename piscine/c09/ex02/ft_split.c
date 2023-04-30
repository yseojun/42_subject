/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:19:56 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/07 23:50:27 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	counting_str(char *str, char *sep)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (is_sep(*str, sep))
		{
			while (is_sep(*str, sep))
				str++;
		}
		else if (!is_sep(*str, sep))
		{
			while (*str && !is_sep(*str, sep))
				str++;
			count++;
		}
	}
	return (count + 1);
}

int	split_put(char *str, char *charset, char **output, int n)
{
	int	i;

	i = 0;
	while (str[i] && !is_sep(str[i], charset))
		i++;
	output[n] = (char *)malloc(sizeof(char *) * (i + 1));
	if (!output[n])
		return (0);
	i = 0;
	while (str[i] && !is_sep(str[i], charset))
	{
		output[n][i] = str[i];
		i++;
	}
	output[n][i] = '\0';
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	char	**output;
	int		n;

	n = 0;
	output = (char **)malloc(sizeof(char *) * counting_str(str, charset));
	if (!output)
		return (0);
	while (*str)
	{
		if (is_sep(*str, charset))
		{
			while (is_sep(*str, charset))
				str++;
		}
		else if (!is_sep(*str, charset))
		{
			if (!split_put(str, charset, output, n))
				return (0);
			while (*str && !is_sep(*str, charset))
				str++;
			n++;
		}
	}
	output[n] = 0;
	return (output);
}
/*
#include <stdio.h>
int	main ()
{
	int	n = 0;
	char *str = " I want one try ";
	char *charset = " ";
	char **out = ft_split(str, charset);
	
	while (out[n])
		printf("%s\n", out[n++]);
}
*/
