/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_vec4.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:33:27 by juloo             #+#    #+#             */
/*   Updated: 2016/03/25 19:11:08 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_VEC4_H
# define MATH_VEC4_H

typedef struct s_vec4		t_vec4;

/*
** ========================================================================== **
** Vec4
** -
** VEC4(X, Y, Z, W)		t_vec4 constructor {X, Y, Z, W}
** VEC4_0()				t_vec4 constructor {0, 0, 0, 0}
** VEC4_1(A+)			t_vec4 constructor {A, A, A, A}
** -
** VEC4_ADD(A+, B+)		t_vec4 A + t_vec4 B
** VEC4_SUB(A+, B+)		t_vec4 A - t_vec4 B
** VEC4_MUL(A+, B+)		t_vec4 A * t_vec4 B
** VEC4_DIV(A+, B+)		t_vec4 A / t_vec4 B
** -
** VEC4_ADD1(A+, B+)	t_vec4 A + float B
** VEC4_SUB1(A+, B+)	t_vec4 A - float B
** VEC4_MUL1(A+, B+)	t_vec4 A * float B
** VEC4_DIV1(A+, B+)	t_vec4 A / float B
** -
** VEC4_DOT(A+, B+)		t_vec4 A dot t_vec4 B
*/

# define VEC4(X, Y, Z, W)	((t_vec4){(X), (Y), (Z), (W)})
# define VEC4_0()			((t_vec4){0.f, 0.f, 0.f, 0.f})
# define VEC4_1(A)			((t_vec4){(A), (A), (A), (A)})

struct			s_vec4
{
	float			x;
	float			y;
	float			z;
	float			w;
};

# define VEC4_DOT(A, B)		((A).x*(B).x+(A).y*(B).y+(A).z*(B).z+(A).w*(B).w)

# define VEC4_ADD(A, B)		(_VEC4_OP((A), +, (B)))
# define VEC4_SUB(A, B)		(_VEC4_OP((A), -, (B)))
# define VEC4_MUL(A, B)		(_VEC4_OP((A), *, (B)))
# define VEC4_DIV(A, B)		(_VEC4_OP((A), /, (B)))

# define VEC4_ADD1(A, B)	(_VEC4_OP1((A), +, (B)))
# define VEC4_SUB1(A, B)	(_VEC4_OP1((A), -, (B)))
# define VEC4_MUL1(A, B)	(_VEC4_OP1((A), *, (B)))
# define VEC4_DIV1(A, B)	(_VEC4_OP1((A), /, (B)))

# define _VEC4_OP(A,O,B)	(VEC4(A.x O B.x, A.y O B.y, A.z O B.z, A.w O B.w))
# define _VEC4_OP1(A,O,B)	(VEC4(A.x O B, A.y O B, A.z O B, A.w O B))

#endif
