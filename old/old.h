/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 19:31:00 by juloo             #+#    #+#             */
/*   Updated: 2015/11/11 19:32:49 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OLD_H
# define OLD_H

# include "libft.h"

/*
** ========================================================================== **
** Str
*/

t_bool			ft_match(char *str, char *pattern);
int				ft_nmatch(char *str, char *pattern);
t_bool			ft_hidenp(char *hide, char *str);

t_bool			ft_sisint(const char *s);

int				ft_strichri(const char *str, char c);
char			*ft_strchr(const char *s, char c);

t_uint			ft_strcskipe(const char *str, const char *skip);
t_bool			ft_strequ(const char *s1, const char *s2);

t_bool			ft_strncase(const char *s1, const char *s2, t_uint n);

char			*ft_strdup(const char *str);
char			*ft_strndup(const char *src, t_uint len);

/*
** ========================================================================== **
** Conv
*/

int				ft_atoi(const char *str);
t_long			ft_atol(const char *str);
double			ft_atod(const char *str);

int				ft_atoub(const char *str, t_uint *nb);

int				ft_itoab(int n, char *buff);

t_ulong			ft_basetoi(const char *str, const char *base);

/*
** ========================================================================== **
** Sort
*/

void			ft_simplesort(void **tab, int length, int (*cmp)());
void			ft_mergesort(void **tab, int length, int (*cmp)());
void			ft_bubblesort(void **tab, int length, int (*cmp)());
void			ft_insertsort(void **tab, int length, int (*cmp)());
void			ft_quicksort(void **tab, int length, int (*cmp)());

t_bool			ft_issort(void **tab, int length, int (*cmp)());

/*
** ========================================================================== **
** Misc
*/

int				ft_exec(char **argv, char **env);

char			*ft_getenv(char const *name, char **env);

#endif
