/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_complex.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:29:39 by juloo             #+#    #+#             */
/*   Updated: 2016/03/13 22:30:22 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_COMPLEX_H
# define MATH_COMPLEX_H

# include "ft/math_vec2.h"

typedef t_vec2				t_complex;

/*
** ========================================================================== **
** Complex number
** -
** COMPLEX(A, B)		t_complex constructor
** -
** COMPLEX_ADD(A+, B+)	t_complex A + t_complex B
** COMPLEX_SUB(A+, B+)	t_complex A - t_complex B
** COMPLEX_MUL(A+, B+)	t_complex A * t_complex B
** COMPLEX_DIV(A+, B+)	t_complex A / t_complex B
** -
** COMPLEX_MUL1(A+, B+)	t_complex A * float B
*/

# define COMPLEX			VEC2

# define COMPLEX_ADD		VEC2_ADD
# define COMPLEX_SUB		VEC2_SUB

# define COMPLEX_MUL1		VEC2_MUL1

# define COMPLEX_MUL(A, B)	(VEC2(((A).x*(B).x)-((A).y*(B).y),_CMPLX_MUL(A,B)))

# define COMPLEX_DIV(A, B)	(VEC2(VEC2_DOT(A,B)/VEC2_DOT(B,B),_CMPLX_DIV(A,B)))

/*
** -
*/

# define _CMPLX_MUL(A, B)	(((A).x*(B).y)+((A).y*(B).x))
# define _CMPLX_DIV(A, B)	((((A).y*(B).x)-((A).x*(B).y))/VEC2_DOT(B,B))

#endif
