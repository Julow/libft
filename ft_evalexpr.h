/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evalexpr.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 23:01:35 by juloo             #+#    #+#             */
/*   Updated: 2015/08/10 14:20:27 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EVALEXPR_H
# define FT_EVALEXPR_H

# include "libft.h"

typedef struct	s_op
{
	char			symbol;
	int				priority;
	float			(*f)(float a, float b);
}				t_op;

typedef struct	s_func
{
	t_sub			name;
	float			(*f)(float a);
}				t_func;

typedef struct	s_expr
{
	t_op			*op;
	struct s_expr	*next;
	float			n;
}				t_expr;

# define MAX_PRIORITY	3

t_bool			parse_op(char c, t_expr *expr);
t_bool			parse_func(t_sub sub, int *i_ptr, float *value);

t_bool			eval_value(t_sub sub, int *i_ptr, float *value);

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
t_bool			ft_evalexpr(t_sub expr, float *result);

/*
** ft_subfloat
** -
** Parse a float number
** Stop at the first invalid char
** Store result in the *f param
** -
** Return the length of the float (in the string)
**  on error return 0 (0 char parsed)
** -
** Valid float:
**   0  0.  0.0  .0  0,  0,0  ,0  .  ,
*/
int				ft_subfloat(t_sub sub, float *f);

#endif
