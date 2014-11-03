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

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <string.h>

void			*ft_memset(void *b, int c, size_t len);

void			ft_bzero(void *s, size_t n);

void			*ft_memcpy(void *dst, void *src, size_t n);

void			*ft_memccpy(void *dst, void *src, int c, size_t n);

void			*ft_memmove(void *dst, void *src, size_t len);

// memchr
// memcmp

unsigned int	ft_strlen(char *str);

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
// atoi
// isalpha
// isdigit
// isalnum
// isascii
// isprint
// toupper
// tolower

#endif
