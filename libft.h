/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:52:52 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/03 11:52:56 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, void *src, size_t n);
void			*ft_memccpy(void *dst, void *src, int c, size_t n);
void			*ft_memmove(void *dst, void *src, size_t len);
void			*ft_memchr(void *s, int c, size_t n);
int				ft_memcmp(void *s1, void *s2, size_t n);

size_t			ft_strlen(char *str);

char			*ft_strdup(char *src);

char			*ft_strcpy(char *dst, char *src);

char			*ft_strncpy(char *dst, char *src, size_t len);

// strcat
// strncat
// strlcat
// strchr
// strrchr
// strstr
// strnstr
// strcmp
// strncmp
int				ft_atoi(char *str);

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);

int				ft_toupper(int c);
int				ft_tolower(int c);

#endif
