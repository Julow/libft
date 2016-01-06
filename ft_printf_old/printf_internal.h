/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 15:12:10 by juloo             #+#    #+#             */
/*   Updated: 2015/12/10 19:17:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_INTERNAL_H
# define PRINTF_INTERNAL_H

# include "libft.h"
# include "ft_out.h"

# include <stdarg.h>

typedef struct	s_printf
{
	t_out			*out;
	int				printed;
	va_list			*ap;
}				t_printf;

# define SPRINTF_MAX	(1024 * 1024)

typedef enum	e_pflen_t
{
	pflen_hh,
	pflen_h,
	pflen_ll,
	pflen_l,
	pflen_L,
	pflen_j,
	pflen_t,
	pflen_I,
	pflen_z,
	pflen_q,
	pflen_def
}				t_pflen_t;

# define PFLAG_ALT		(BIT(1))
# define PFLAG_SPACE	(BIT(2))
# define PFLAG_ZERO		(BIT(3))
# define PFLAG_MOINS	(BIT(4))
# define PFLAG_PLUS		(BIT(5))
# define PFLAG_GROUP	(BIT(6))
# define PFLAG_CENTER	(BIT(7))
# define PFLAG_RIGHT	(BIT(8))
# define PFLAG_LOWER	(BIT(9))
# define PFLAG_UPPER	(BIT(10))

# define PFLAG_PRECI	(BIT(24))

# define PUTLONG_BUFF	21

typedef struct	s_pfopt
{
	int				flags;
	int				width;
	int				preci;
	t_pflen_t		length;
	char			format;
}				t_pfopt;

typedef struct	s_pflen
{
	t_sub			name;
	t_pflen_t		length;
}				t_pflen;

typedef struct	s_pfflag
{
	char			name;
	int				mask;
	int				override;
}				t_pfflag;

typedef struct	s_pformat
{
	char			name;
	void			(*f)(t_printf*, t_pfopt*);
}				t_pformat;

typedef enum	e_meta_t
{
	meta_t_str,
	meta_t_func,
	meta_t_nope
}				t_meta_t;

# define META_T(s,t,d)	{(s), sizeof(s) - 1, (t), (d)}

typedef struct	s_meta
{
	char			*name;
	int				name_len;
	int				type;
	void			*data;
}				t_meta;

void			writef(t_printf *pf, const char *format);

/*
** formats
*/
int				parse_format(t_printf *pf, const char *format);

int64_t			get_arg(t_printf *pf, t_pfopt *opt);
uint64_t			get_unsigned_arg(t_printf *pf, t_pfopt *opt);
long double		get_float_arg(t_printf *pf, t_pfopt *opt);

bool			is_separator(char c);
void			margin_before(t_printf *pf, t_pfopt *opt, int len);
void			margin_after(t_printf *pf, t_pfopt *opt, int len);
int				ft_numlen(int64_t num, int base);
int				ft_unumlen(uint64_t num, int base);

void			flag_d(t_printf *pf, t_pfopt *opt);
void			flag_c(t_printf *pf, t_pfopt *opt);
void			flag_percent(t_printf *pf, t_pfopt *opt);
void			flag_s(t_printf *pf, t_pfopt *opt);
void			flag_n(t_printf *pf, t_pfopt *opt);
void			flag_x(t_printf *pf, t_pfopt *opt);
void			flag_o(t_printf *pf, t_pfopt *opt);
void			flag_b(t_printf *pf, t_pfopt *opt);
void			flag_p(t_printf *pf, t_pfopt *opt);
void			flag_u(t_printf *pf, t_pfopt *opt);
void			flag_other(t_printf *pf, t_pfopt *opt, char c);
void			flag_r(t_printf *pf, t_pfopt *opt);
void			flag_rr(t_printf *pf, t_pfopt *opt);
void			flag_w(t_printf *pf, t_pfopt *opt);
void			flag_f(t_printf *pf, t_pfopt *opt);

/*
** metas
*/
int				parse_meta(t_printf *pf, t_pfopt *opt, const char *format);

int				end_meta(const char *format);

int				meta_t(t_printf *pf, t_pfopt *opt, const char *format);
int				meta_nl(t_printf *pf, t_pfopt *opt, const char *format);
int				meta_fl(t_printf *pf, t_pfopt *opt, const char *format);

#endif
