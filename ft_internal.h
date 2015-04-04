/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_internal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 19:49:39 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/04 01:54:21 by jaguillo         ###   ########.fr       */
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
# define FLAG_R_EQU		(1 << 3)
# define FLAG_R_SET		(1 << 16)
# define FLAG_R_IS		(1 << 17)
# define FLAG_R_PRE		(1 << 18)
# define FLAG_R_SUB		(1 << 19)

const char		*parse_reg_pre(t_reg *reg, const char *pattern);
const char		*parse_reg_is(t_reg *reg, const char *pattern);
const char		*parse_reg_sub(t_reg *reg, const char *str);
const char		*reg_parse(t_reg *reg, const char *pattern);

const char		*reg_reg(t_reg *r, const char *s, const char *p, t_uint l);
const char		*reg_match(const char *str, const char **pattern);
const char		*reg_test(const char *str, const char *pattern);

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

typedef struct	s_printf
{
	t_out			*out;
	int				printed;
	va_list			*ap;
}				t_printf;

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
	char			*name;
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

typedef enum	s_meta_t
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

t_long			get_arg(t_printf *pf, t_pfopt *opt);
t_ulong			get_unsigned_arg(t_printf *pf, t_pfopt *opt);
long double		get_float_arg(t_printf *pf, t_pfopt *opt);

t_bool			is_separator(char c);
void			margin_before(t_printf *pf, t_pfopt *opt, int len);
void			margin_after(t_printf *pf, t_pfopt *opt, int len);
int				ft_numlen(t_long num, int base);
int				ft_unumlen(t_ulong num, int base);

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

/*
** metas
*/
int				parse_meta(t_printf *pf, t_pfopt *opt, const char *format);

int				end_meta(const char *format);

int				meta_t(t_printf *pf, t_pfopt *opt, const char *format);
int				meta_nl(t_printf *pf, t_pfopt *opt, const char *format);
int				meta_fl(t_printf *pf, t_pfopt *opt, const char *format);

#endif
