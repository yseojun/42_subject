/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojyang <seojyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:48:48 by seojyang          #+#    #+#             */
/*   Updated: 2022/11/19 17:17:55 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTIL_H
# define FT_UTIL_H

# include <stdlib.h>
# include <unistd.h>

int		ft_isdigit(int c);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
char	*ft_uitohex(unsigned int n);
char	*ft_ultohex(unsigned long long n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, int len);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strtrim(char *s1, char const *set);
int		ft_toupper(int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_chardup(char c);

#endif