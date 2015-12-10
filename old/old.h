/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 19:31:00 by juloo             #+#    #+#             */
/*   Updated: 2015/12/10 19:17:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OLD_H
# define OLD_H

# include "libft.h"

/*
** ========================================================================== **
** Str
*/

bool			ft_match(char *str, char *pattern);
int				ft_nmatch(char *str, char *pattern);
bool			ft_hidenp(char *hide, char *str);

bool			ft_sisint(const char *s);

int				ft_strichri(const char *str, char c);
char			*ft_strchr(const char *s, char c);

uint32_t			ft_strcskipe(const char *str, const char *skip);
bool			ft_strequ(const char *s1, const char *s2);

bool			ft_strncase(const char *s1, const char *s2, uint32_t n);

char			*ft_strdup(const char *str);
char			*ft_strndup(const char *src, uint32_t len);

/*
** ========================================================================== **
** Conv
*/

int				ft_atoi(const char *str);
int64_t			ft_atol(const char *str);
double			ft_atod(const char *str);

int				ft_atoub(const char *str, uint32_t *nb);

int				ft_itoab(int n, char *buff);

uint64_t			ft_basetoi(const char *str, const char *base);

/*
** ========================================================================== **
** Sort
*/

void			ft_simplesort(void **tab, int length, int (*cmp)());
void			ft_mergesort(void **tab, int length, int (*cmp)());
void			ft_bubblesort(void **tab, int length, int (*cmp)());
void			ft_insertsort(void **tab, int length, int (*cmp)());
void			ft_quicksort(void **tab, int length, int (*cmp)());

bool			ft_issort(void **tab, int length, int (*cmp)());

/*
** ========================================================================== **
** Misc
*/

int				ft_exec(char **argv, char **env);

char			*ft_getenv(char const *name, char **env);

#endif
