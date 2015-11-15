/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 01:32:23 by juloo             #+#    #+#             */
/*   Updated: 2015/11/15 16:27:34 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_INTERNAL_H
# define PRINTF_INTERNAL_H

# include "ft_printf.h"
# include "ft_vprintf.h"
# include "ft_out.h"

/*
** ========================================================================== **
** Formatter
*/

typedef enum e_f_length		t_f_length;
typedef struct s_f_info		t_f_info;

typedef struct s_f_len_def	t_f_len_def;
typedef struct s_f_flag_def	t_f_flag_def;
typedef struct s_format_def	t_format_def;

enum e_f_length
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

struct s_f_info
{
	t_f_length		length;
	char			format;
};

struct s_f_len_def
{
	t_sub			name;
	t_f_length		length;
};

struct s_f_flag_def
{
	char			name;
	int				mask;
	int				override;
};

struct s_format_def
{
	char			name;
	void			(*f)(t_out*, t_f_info*, va_list*);
};

int				exec_format(t_out *out, char const *format, va_list *ap);

int64_t			get_signed_arg(va_list *ap, t_f_length length);
uint64_t		get_unsigned_arg(va_list *ap, t_f_length length);
double			get_float_arg(va_list *ap, t_f_length length);

void			format_d(t_out *out, t_f_info *info, va_list *ap);
void			format_x(t_out *out, t_f_info *info, va_list *ap);
void			format_o(t_out *out, t_f_info *info, va_list *ap);
void			format_u(t_out *out, t_f_info *info, va_list *ap);
void			format_b(t_out *out, t_f_info *info, va_list *ap);

void			format_s(t_out *out, t_f_info *info, va_list *ap);
void			format_c(t_out *out, t_f_info *info, va_list *ap);

void			format_f(t_out *out, t_f_info *info, va_list *ap);

// void			format_r(t_out *out, t_f_info *info, va_list *ap);
// void			format_w(t_out *out, t_f_info *info, va_list *ap);

void			format_flush(t_out *out, t_f_info *info, va_list *ap);
void			format_endl(t_out *out, t_f_info *info, va_list *ap);
void			format_default(t_out *out, t_f_info *info, va_list *ap);

/*
** ========================================================================== **
** FTOUT
*/

# define FTOUT_BUFF		512

void			ftout_flush(t_ftout *out);

#endif
