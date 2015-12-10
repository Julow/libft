/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evalexpr.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 23:01:35 by juloo             #+#    #+#             */
/*   Updated: 2015/12/10 19:14:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EVALEXPR_H
# define FT_EVALEXPR_H

# include "ft/libft.h"

struct			s_op
{
	char			symbol;
	int				priority;
	float			(*f)(float a, float b);
};

struct			s_func
{
	t_sub			name;
	float			(*f)(float a);
};

struct			s_expr
{
	struct s_op		*op;
	struct s_expr	*next;
	float			n;
};

# define MAX_PRIORITY	3

bool			parse_op(char c, struct s_expr *expr);
bool			parse_func(t_sub sub, int *i_ptr, float *value);

bool			eval_value(t_sub sub, int *i_ptr, float *value);

float			op_plus(float a, float b);
float			op_moins(float a, float b);
float			op_mult(float a, float b);
float			op_div(float a, float b);

/*
** ft_evalexpr
** -
** Evaluate a math expresion
** -
** Supported operators:
**   * / - + % ^ ( )
** Supported functions:
**   cos  sin   tan   acos  asin  atan
**   exp  log   log2  log10 sqrt
**   ceil floor round abs
*/
bool			ft_evalexpr(t_sub expr, float *result);

#endif
