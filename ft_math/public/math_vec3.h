/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_vec3.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:31:55 by juloo             #+#    #+#             */
/*   Updated: 2016/04/05 09:23:49 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_VEC3_H
# define MATH_VEC3_H

# include "ft/math_vec2.h"

typedef struct s_vec3		t_vec3;

/*
** ========================================================================== **
** Vec3
** -
** VEC3(X, Y, Z)		t_vec3 constructor {X, Y, Z}
** VEC3_0()				t_vec3 constructor {0, 0, 0}
** VEC3_1(A+)			t_vec3 constructor {A, A, A}
** VEC3_2(V, Z)			t_vec3 constructor {V.x, V.y, Z}
** VEC3_UP()			t_vec3 constructor {0, 1, 0}
** -
** VEC3_X(A+, X)		t_vec3 constructor {X, A.y, A.z}
** VEC3_Y(A+, Y)		t_vec3 constructor {A.X, Y, A.z}
** VEC3_Z(A+, Z)		t_vec3 constructor {A.X, A.y, Z}
** -
** VEC3_ADD(A+, B+)		t_vec3 A + t_vec3 B
** VEC3_SUB(A+, B+)		t_vec3 A - t_vec3 B
** VEC3_MUL(A+, B+)		t_vec3 A * t_vec3 B
** VEC3_DIV(A+, B+)		t_vec3 A / t_vec3 B
** -
** VEC3_ADD1(A+, B+)	t_vec3 A + float B
** VEC3_SUB1(A+, B+)	t_vec3 A - float B
** VEC3_MUL1(A+, B+)	t_vec3 A * float B
** VEC3_DIV1(A+, B+)	t_vec3 A / float B
** -
** VEC3_DOT(A+, B+)		t_vec3 A dot t_vec3 B
** VEC3_CROSS(A+, B+)	t_vec3 A cross t_vec3 B
** -
** ft_vec3norm(V)		Return normalized vector of V
** ft_vec3cross(A, B)	Return cross product between A and B
** ft_vec3dot(A, B)		Function version of VEC3_DOT
** ft_vec3mix(A, B, M)	Return the mix of A and B for M
** ft_vec3length(V)		Return the length of V
** ft_vec3dist(A, B)	Return the distance between A and B
** ft_vec3dist2(A, B)	Return the sqare of the distance between A and B
*/

# define VEC3(X, Y, Z)		((t_vec3){(X), (Y), (Z)})
# define VEC3_0()			((t_vec3){0.f, 0.f, 0.f})
# define VEC3_1(A)			((t_vec3){(A), (A), (A)})
# define VEC3_2(V, Z)		((t_vec3){(V).x, (V).y, (Z)})

# define VEC3_UP()			(VEC3(0.f, 1.f, 0.f))

struct			s_vec3
{
	float			x;
	float			y;
	float			z;
};

# define VEC3_X(V,X)		(VEC3((X), (V).y, (V).z))
# define VEC3_Y(V,Y)		(VEC3((V).x, (Y), (V).z))
# define VEC3_Z(V,Z)		(VEC3((V).x, (V).y, (Z)))

# define VEC3_ADD(A, B)		(_VEC3_OP((A), +, (B)))
# define VEC3_SUB(A, B)		(_VEC3_OP((A), -, (B)))
# define VEC3_MUL(A, B)		(_VEC3_OP((A), *, (B)))
# define VEC3_DIV(A, B)		(_VEC3_OP((A), /, (B)))

# define VEC3_ADD1(A, B)	(_VEC3_OP1((A), +, (B)))
# define VEC3_SUB1(A, B)	(_VEC3_OP1((A), -, (B)))
# define VEC3_MUL1(A, B)	(_VEC3_OP1((A), *, (B)))
# define VEC3_DIV1(A, B)	(_VEC3_OP1((A), /, (B)))

# define VEC3_DOT(A, B)		(((A).x*(B).x) + ((A).y*(B).y) + ((A).z*(B).z))
# define VEC3_CROSS(A, B)	(VEC3 _VEC3_CROSS((A), (B)))

# define VEC3_MIN(A, B)		(VEC3(MIN(A.x, B.x), MIN(A.y, B.y), MIN(A.z, B.z)))

t_vec3			ft_vec3norm(t_vec3 v);

t_vec3			ft_vec3cross(t_vec3 a, t_vec3 b);
float			ft_vec3dot(t_vec3 a, t_vec3 b);

t_vec3			ft_vec3mix(t_vec3 a, t_vec3 b, float mix);

float			ft_vec3length(t_vec3 v);
float			ft_vec3dist(t_vec3 a, t_vec3 b);
float			ft_vec3dist2(t_vec3 a, t_vec3 b);

/*
** -
*/

t_vec3			ft_vec3sub(t_vec3 a, t_vec3 b);
t_vec3			ft_vec3front(t_vec2 a);
void			ft_vec3rotate(t_vec3 *v, t_vec3 rotate);

# define _VEC3_CROSS(A, B)	(A.y*B.z-A.z*B.y,A.z*B.x-A.x*B.z,A.x*B.y-A.y*B.x)

# define _VEC3_OP(A,O,B)	(VEC3(A.x O B.x, A.y O B.y, A.z O B.z))
# define _VEC3_OP1(A,O,B)	(VEC3(A.x O B, A.y O B, A.z O B))

#endif
