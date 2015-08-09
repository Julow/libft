/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evalexpr.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 23:01:35 by juloo             #+#    #+#             */
/*   Updated: 2015/08/10 01:57:32 by juloo            ###   ########.fr       */
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

typedef struct	s_expr
{
	t_op			*op;
	struct s_expr	*next;
	float			n;
}				t_expr;

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
**   * / - +
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
