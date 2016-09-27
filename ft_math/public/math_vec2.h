/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_vec2.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:31:03 by juloo             #+#    #+#             */
/*   Updated: 2016/09/27 16:40:30 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_VEC2_H
# define MATH_VEC2_H

# include "ft/libft.h"

/*
** ========================================================================== **
** Vec2
** -
** VEC2_0()				t_vec2 constructor {0, 0}
** -
** VEC2_ADD(A+, B+)		t_vec2 A + t_vec2 B
** VEC2_SUB(A+, B+)		t_vec2 A - t_vec2 B
** VEC2_MUL(A+, B+)		t_vec2 A * t_vec2 B
** VEC2_DIV(A+, B+)		t_vec2 A / t_vec2 B
** -
** VEC2_ADD1(A+, B+)	t_vec2 A + float B
** VEC2_SUB1(A+, B+)	t_vec2 A - float B
** VEC2_MUL1(A+, B+)	t_vec2 A * float B
** VEC2_DIV1(A+, B+)	t_vec2 A / float B
** -
** VEC2_DOT(A+, B+)		t_vec2 A dot t_vec2 B
*/

# define VEC2_0()			((t_vec2){0.f, 0.f})

# define VEC2_ADD(A, B)		(_VEC2_OP((A), +, (B)))
# define VEC2_SUB(A, B)		(_VEC2_OP((A), -, (B)))
# define VEC2_MUL(A, B)		(_VEC2_OP((A), *, (B)))
# define VEC2_DIV(A, B)		(_VEC2_OP((A), /, (B)))

# define VEC2_ADD1(A, B)	(_VEC2_OP1((A), +, (B)))
# define VEC2_SUB1(A, B)	(_VEC2_OP1((A), -, (B)))
# define VEC2_MUL1(A, B)	(_VEC2_OP1((A), *, (B)))
# define VEC2_DIV1(A, B)	(_VEC2_OP1((A), /, (B)))

# define VEC2_DOT(A, B)		(((A).x*(B).x) + ((A).y*(B).y))

/*
** -
*/

# define _VEC2_OP(A,O,B)	(VEC2(A.x O B.x, A.y O B.y))
# define _VEC2_OP1(A,O,B)	(VEC2(A.x O B, A.y O B))

#endif
