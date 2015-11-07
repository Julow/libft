/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 17:00:20 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/19 11:22:06 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OUT_H
# define FT_OUT_H

# include "libft.h"

/*
** ========================================================================== **
** Use the struct s_out (t_out) to write to a fd
** ----
** Constructors:
**  OUT (fd, buff, buff_size)	Create a file out
**  DSTR_OUT (dstr)				Create a dynamic string (ft_dstr) out
**  BUFF_OUT (buff, buff_size)	Create a static (circular) buffer out
*/

# define OUT_NOFLUSH	(1 << 1)
# define OUT_DSTR		(1 << 2)

# define OUT(f,b,l)		((t_out){(b), 0, (l), (f), 0})
# define DSTR_OUT(d)	((t_out){(char*)(d), 0, 0, -1, OUT_DSTR})
# define BUFF_OUT(b,l)	((t_out){(b), 0, (l), -1, OUT_NOFLUSH})

struct			s_out
{
	char			*buff;
	int				i;
	int				length;
	int				fd;
	int				flags;
};

void			ft_write(t_out *out, const char *data, t_uint len);
void			ft_writestr(t_out *out, const char *str);
void			ft_writechar(t_out *out, char c);
void			ft_writenchar(t_out *out, char c, int n);
void			ft_writenl(t_out *out);
void			ft_writeint(t_out *out, int n);
void			ft_writebase(t_out *out, t_ulong n, const char *base);
void			ft_writedouble(t_out *out, double d, int preci);
int				ft_flush(t_out *out);

/*
** Same as ft_printf but write to a t_out
*/
int				ft_writef(t_out *out, const char *format, ...);

/*
** ========================================================================== **
** static t_out FTOUT
*/

extern t_out	g_ftout;

# define DEF_PRECI		7

# define FTOUT			(&g_ftout)

# define P(f, ...)		(ft_writef(FTOUT, (f), __VA_ARGS__))
# define PS(s)			(ft_writestr(FTOUT, (s)))
# define PC(c)			(ft_writechar(FTOUT, (c)))
# define PCN(c,n)		(ft_writenchar(FTOUT, (c), (n)))
# define PI(i)			(ft_writeint(FTOUT, (i)))
# define PB(i,b)		(ft_writebase(FTOUT, (i), (b)))
# define PF(f)			(ft_writedouble(FTOUT, (f), DEF_PRECI))
# define PFP(f,p)		(ft_writedouble(FTOUT, (f), (p)))
# define NL				(ft_writenl(FTOUT))
# define FL				(ft_flush(FTOUT))

void			ft_out(int fd);

void			ft_hexdump(const void *data, t_uint len);

#endif
