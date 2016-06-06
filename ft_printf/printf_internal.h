/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 01:32:23 by juloo             #+#    #+#             */
/*   Updated: 2016/06/06 17:10:29 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_INTERNAL_H
# define PRINTF_INTERNAL_H

# include "ft/ft_out.h"
# include "ft/ft_printf.h"
# include "ft/ft_vprintf.h"

/*
** ========================================================================== **
** Formatter
*/

# define PRINTF_F_ALT		(1 << 15)

typedef enum e_f_length		t_f_length;
typedef struct s_f_info		t_f_info;

typedef struct s_f_len_def	t_f_len_def;
typedef void				(*t_format_def)(t_out *, t_f_info *, va_list *);

enum		e_f_length
{
	f_length_hh,
	f_length_h,
	f_length_ll,
	f_length_l,
	f_length_j,
	f_length_t,
	f_length_z,
	f_length_q,
	f_length_def
};

struct		s_f_info
{
	t_f_length		length;
	char			format;
};

struct		s_f_len_def
{
	t_sub			name;
	t_f_length		length;
};

int			exec_format(t_out *out, char const *format, va_list *ap);

int			exec_subformat(t_out *out, char const *fmt, char end, va_list *ap);

int64_t		get_signed_arg(va_list *ap, t_f_length length);
uint64_t	get_unsigned_arg(va_list *ap, t_f_length length);
double		get_float_arg(va_list *ap, t_f_length length);

void		format_d(t_out *out, t_f_info *info, va_list *ap);
void		format_x(t_out *out, t_f_info *info, va_list *ap);
void		format_o(t_out *out, t_f_info *info, va_list *ap);
void		format_u(t_out *out, t_f_info *info, va_list *ap);
void		format_b(t_out *out, t_f_info *info, va_list *ap);

void		format_s(t_out *out, t_f_info *info, va_list *ap);
void		format_c(t_out *out, t_f_info *info, va_list *ap);

void		format_f(t_out *out, t_f_info *info, va_list *ap);

void		format_flush(t_out *out, t_f_info *info, va_list *ap);
void		format_endl(t_out *out, t_f_info *info, va_list *ap);
void		format_default(t_out *out, t_f_info *info, va_list *ap);

/*
** ========================================================================== **
** Logs
*/

typedef struct s_log_info		t_log_info;

struct		s_log_info
{
	t_sub		prefix;
	int			fd;
	bool		enabled;
};

/*
** ========================================================================== **
** FTOUT
*/

# define FTOUT_BUFF		512

void		ftout_flush(t_ftout *out);

/*
** ========================================================================== **
** Dstr append out
*/

typedef struct s_append_out		t_append_out;

struct		s_append_out
{
	t_out		out;
	t_dstr		*dst;
};

# define APPEND_OUT(S)	((t_append_out){OUT("", 0, &append_out_flush), (S)})

void		append_out_flush(t_append_out *out);

#endif
