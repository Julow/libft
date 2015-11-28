/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 16:59:59 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/27 23:45:43 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUFF_H
# define FT_BUFF_H

# include "ft/libft.h"

typedef struct s_buff		t_buff;

/*
** ========================================================================== **
** Use the struct s_buff (t_buff) to read and parse a file
**  BUFF() macro init a file buff
** Can parse simple string
**  SBUFF() macro init a string buff
*/

# define BI(b)			((b)->i < (b)->length)
# define BG(b)			(BI(b) ? (b)->data[(b)->i] : ft_buffget(b))
# define BR(b)			(BI(b) ? (b)->data[(b)->i++] : ft_readbuff(b))
# define BIS(b,c)		(BG(b) == c && ++((b)->i))
# define BIF(b,f)		((f)(BG(b)) && ++((b)->i))

# define BF_EOF			20
# define BF_STR			21

# define BEOF(b)		(FLAG((b)->fd, BF_EOF) || (BSTR(b) && !BI(b)))
# define BSTR(b)		FLAG((b)->fd, BF_STR)
# define BFD(b)			((b)->fd & 0xFF)

# define BUFF(f,b,l)	((t_buff){(b), 0, 0, (l), (f) & 0xFF})
# define SBUFF(s,l)		((t_buff){(s), 0, (l), (l), -1 & 0xFF | BIT(BF_STR)})

struct			s_buff
{
	char			*data;
	int				i;
	int				length;
	int				buff_len;
	int				fd;
};

char			ft_readbuff(t_buff *buff);
char			ft_buffget(t_buff *buff);
void			ft_buffclear(t_buff *buff);

t_bool			ft_parseint(t_buff *buff, int *nb);
t_bool			ft_parselong(t_buff *buff, t_long *nb);
t_bool			ft_parsebase(t_buff *buff, const char *base, t_ulong *nb);
t_bool			ft_parsebasei(t_buff *buff, const char *base, t_ulong *nb);
t_bool			ft_parsenumber(t_buff *buff, t_ulong *nb);
t_bool			ft_parsedouble(t_buff *buff, double *nb);

t_bool			ft_parse(t_buff *buff, const char *parse);
t_bool			ft_parsenot(t_buff *buff, const char *parse);
t_bool			ft_parsestr(t_buff *buff, const char *str);

void			ft_parseendl(t_buff *buff);
t_bool			ft_parsen(t_buff *buff, char *dst, int len);

t_bool			ft_parsef(t_buff *buff, t_bool (*f)(int c));
t_bool			ft_parsespace(t_buff *buff);
t_bool			ft_parsewhite(t_buff *buff);

#endif
