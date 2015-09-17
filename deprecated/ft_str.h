/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 16:15:27 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/17 16:25:49 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H

# include "libft.h"

/*
** ========================================================================== **
** String
*/

char			*ft_strnew(t_uint size);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, t_uint len);
char			*ft_strsub(const char *s, t_uint start, t_uint len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(const char *s);
char			**ft_strsplit(const char *s, char c);

int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, t_uint n);
t_bool			ft_strnequ(const char *s1, const char *s2, t_uint n);
t_bool			ft_strcase(const char *s1, const char *s2);

void			ft_strnadd(char **str, const char *add, t_uint len);

int				ft_strcount(char const *str, t_is mask);

void			ft_strlower(char *str);
void			ft_strupper(char *str);

/*
** ========================================================================== **
** String search
*/

char			*ft_strnchr(const char *s, char c, int len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, t_uint n);

t_uint			ft_strskip(const char *str, const char *skip);
t_uint			ft_strcskip(const char *str, const char *skip);
t_uint			ft_strskipe(const char *str, const char *skip);

char			*ft_strstart(char *str, const char *start);
t_bool			ft_strend(const char *str, const char *end);

int				ft_strbrace(const char *str, char open, char close);

/*
** ========================================================================== **
** String - Useless
*/
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, t_uint n);
t_uint			ft_strlcat(char *dst, const char *src, t_uint size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(int, char*));
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(int, char));

#endif
