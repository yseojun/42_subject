/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:00:35 by seojyang          #+#    #+#             */
/*   Updated: 2022/10/19 22:24:56 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_STRING_H
# define F_STRING_H

int		ft_strlen(char *str);
char	*ft_strcat(char *dest, char *src);
char	*ft_newstr(char *s1, char *s2);
char	*ft_strdup(char *s1);
int		ft_strncmp(char *s1, char *s2, int n);

#endif
