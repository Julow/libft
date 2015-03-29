/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_internal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 19:49:39 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/29 20:25:33 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INTERNAL_H
# define FT_INTERNAL_H

# include "libft.h"

# include <stdarg.h>

/*
** =============
** ft_rmatch
*/

typedef struct	s_reg
{
	int				flags;
	t_uint			from;
	t_uint			to;
	int				reg_len;
	char			*reg;
}				t_reg;

# ifndef REG_START
#  define REG_START		'?'
# endif

# define FLAG_R_NOT		(1 << 1)
# define FLAG_R_CASE	(1 << 2)
# define FLAG_R_SET		(1 << 16)
# define FLAG_R_F		(1 << 17)

const char		*reg_parse(t_reg *reg, const char *pattern);
const char		*reg_match(const char *str, const char **pattern);
const char		*reg_test(const char *str, const char *pattern);
const char		*reg_reg(t_reg *r, const char *s, const char *p, t_uint l);

/*
** =============
** ft_put
*/

# define PUTNBR_BUFF	11
# define PUTLONG_BUFF	21
# define PUTBASE_BUFF	64

/*
** =============
** get_next_line
*/

# ifndef GNL_BUFF
#  define GNL_BUFF		256
# endif

# define GNL_SUCCES		1
# define GNL_EOF		0
# define GNL_ERROR		-1

typedef struct	s_gnlfd
{
	char			*buff;
	int				fd;
	int				length;
	int				offset;
	int				i;
	struct s_gnlfd	*next;
}				t_gnlfd;

/*
** =============
** ft_printf
*/

# define HASF(c)	(ft_strchr(opt->flags, (c)) != NULL)

# define LONG_BUFF	(40)

typedef struct	s_format
{
	char			name;
	void			(*func)();
	char			*disabled;
}				t_format;

typedef struct	s_opt
{
	char			*flags;
	int				width;
	int				preci;
	t_bool			preci_set;
	char const		*length;
	t_format		*format;
}				t_opt;

typedef struct	s_meta
{
	char			*name;
	char			*value;
}				t_meta;

void			parsef(t_string *out, const char *format, va_list *ap);

int				parse_format(t_string *out, const char *format, va_list *ap);

int				parse_meta(t_string *out, const char *format);

void			ft_stringaddupper(t_string *str, const char *add, int len);
void			ft_stringaddlower(t_string *str, const char *add, int len);
int				ft_atoin(const char *str, int len);

void			add_string(t_string *out, const char *add, int len, t_opt *opt);
void			add_nchar(t_string *out, char c, int len, t_opt *opt);
void			pad_preci(t_string *str, int start, t_opt *opt);
t_bool			is_separator(char c);
void			clear_dis(t_opt *opt);

t_long			get_arg(t_opt *opt, va_list *ap);
t_ulong			get_unsigned_arg(t_opt *opt, va_list *ap);
long double		get_float_arg(t_opt *opt, va_list *ap);

void			flag_percent(t_string *out, t_opt *opt, va_list *ap);
void			flag_s(t_string *out, t_opt *opt, va_list *ap);
void			flag_d(t_string *out, t_opt *opt, va_list *ap);
void			flag_o(t_string *out, t_opt *opt, va_list *ap);
void			flag_u(t_string *out, t_opt *opt, va_list *ap);
void			flag_x(t_string *out, t_opt *opt, va_list *ap);
void			flag_c(t_string *out, t_opt *opt, va_list *ap);
void			flag_n(t_string *out, t_opt *opt, va_list *ap);
void			flag_p(t_string *out, t_opt *opt, va_list *ap);
void			flag_e(t_string *out, t_opt *opt, va_list *ap);
void			flag_f(t_string *out, t_opt *opt, va_list *ap);
void			flag_b(t_string *out, t_opt *opt, va_list *ap);
void			flag_r(t_string *out, t_opt *opt, va_list *ap);

#endif
