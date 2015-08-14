/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 01:52:25 by juloo             #+#    #+#             */
/*   Updated: 2015/08/14 01:56:17 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include "libft.h"
# include "ft_array.h"

/*
** Deprecated
*/

/*
** ========================================================================== **
** String
** -
** + fast convertion
** + \0 terminated
** - slow realloc
** - slow insert/remove/replace
*/

typedef struct	s_string
{
	char			*content;
	int				length;
	int				alloc_length;
}				t_string;

t_string		*ft_stringnew(void);
t_string		*ft_stringnews(const char *s);
void			ft_stringini(t_string *str);
void			ft_stringaddc(t_string *str, char c);
void			ft_stringadd(t_string *str, const char *add);
void			ft_stringaddi(t_string *str, int nbr);
void			ft_stringaddil(t_string *str, t_long nbr);
void			ft_stringaddid(t_string *str, double nbr);
void			ft_stringaddd(t_string *str, double d, int preci);
void			ft_stringaddde(t_string *str, double d, int preci);
void			ft_stringaddl(t_string *str, const char *add, int len);
void			ft_stringaddcn(t_string *str, char c, int n);
void			ft_stringsetc(t_string *str, char c, int index);
void			ft_stringset(t_string *str, const char *set, int index);
void			ft_stringsetl(t_string *str, const char *set, int index, int l);
void			ft_stringinsc(t_string *str, char c, int index);
void			ft_stringins(t_string *str, const char *ins, int index);
void			ft_stringinsl(t_string *str, const char *ins, int index, int l);
void			ft_stringrepc(t_string *str, char c, char r);
void			ft_stringrep(t_string *str, const char *chr, const char *rep);
t_string		*ft_stringdup(t_string *str);
t_string		*ft_stringsub(t_string *str, int index, int len);
void			ft_stringrem(t_string *str, int index, int len);
void			ft_stringtrim(t_string *str);
void			ft_stringtrimc(t_string *str, const char *trim);
t_array			*ft_stringsplit(t_string *str, const char *chr);
t_array			*ft_stringsplitc(t_string *str, char c);
int				ft_stringchr(t_string *str, char c);
int				ft_stringstr(t_string *str, const char *chr, int start);
void			ft_stringfree(t_string *str);
void			ft_stringclr(t_string *str);
void			ft_stringkil(void *str);
t_bool			ft_stringext(t_string *str, int need);
int				ft_stringput(t_string *str);
int				ft_stringputfd(t_string *str, int const fd);

/*
** ========================================================================== **
** Buffer extension
*/

int				ft_parsesub(t_buff *buff, t_string *dst, const char *parse);
int				ft_parsesubf(t_buff *buff, t_string *dst, t_bool (*f)(int c));
int				ft_parsesubnf(t_buff *buff, t_string *dst, t_bool (*f)(int c));
int				ft_parseline(t_buff *buff, t_string *dst);
t_bool			ft_parsequote(t_buff *buff, t_string *dst);

/*
** ========================================================================== **
** Pair extension
*/

# include "ft_array.h"

typedef struct	s_pair
{
	t_string		*key;
	void			*value;
}				t_pair;

t_pair			*ft_pairnew(const char *key, void *value);
t_pair			*ft_pairget(t_array *array, const char *key);
int				ft_pairchr(t_array *array, const char *key);
t_pair			*ft_pairrem(t_array *array, const char *key);
void			ft_pairsort(t_array *array);

#endif
