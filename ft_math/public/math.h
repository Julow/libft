/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 12:48:06 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/28 18:42:44 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

typedef struct s_vec2		t_vec2;
typedef struct s_vec3		t_vec3;
typedef struct s_vec4		t_vec4;
typedef struct s_mat4		t_mat4;

/*
** ========================================================================== **
** Vec2
** -
** VEC2(X, Y)			t_vec2 constructor {X, Y}
** VEC2_0()				t_vec2 constructor {0, 0}
** VEC2_1(A+)			t_vec2 constructor {A, A}
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

# define VEC2(X, Y)			((t_vec2){(X), (Y)})
# define VEC2_0()			((t_vec2){0.f, 0.f})
# define VEC2_1(A)			((t_vec2){(A), (A)})

struct			s_vec2
{
	float			x;
	float			y;
};

# define VEC2_ADD(A, B)		(_VEC2_OP((A), +, (B)))
# define VEC2_SUB(A, B)		(_VEC2_OP((A), -, (B)))
# define VEC2_MUL(A, B)		(_VEC2_OP((A), *, (B)))
# define VEC2_DIV(A, B)		(_VEC2_OP((A), /, (B)))

# define VEC2_ADD1(A, B)	(_VEC2_OP1((A), +, (B)))
# define VEC2_SUB1(A, B)	(_VEC2_OP1((A), -, (B)))
# define VEC2_MUL1(A, B)	(_VEC2_OP1((A), *, (B)))
# define VEC2_DIV1(A, B)	(_VEC2_OP1((A), /, (B)))

# define VEC2_DOT(A, B)		(((A).x*(B).x) + ((A).y*(B).y))

# define _VEC2_OP(A,O,B)	(VEC2(A.x O B.x, A.y O B.y))
# define _VEC2_OP1(A,O,B)	(VEC2(A.x O B, A.y O B))

/*
** ========================================================================== **
** Vec3
** -
** VEC3(X, Y, Z)		t_vec3 constructor {X, Y, Z}
** VEC3_0()				t_vec3 constructor {0, 0, 0}
** VEC3_1(A+)			t_vec3 constructor {A, A, A}
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
** -
** ft_vec3norm(V)		Return normalized vector of V
** ft_vec3cross(A, B)	Return cross product between A and B
** ft_vec3dot(A, B)		Function version of VEC3_DOT
*/

# define VEC3(X, Y, Z)		((t_vec3){(X), (Y), (Z)})
# define VEC3_0()			((t_vec3){0.f, 0.f, 0.f})
# define VEC3_1(A)			((t_vec3){(A), (A), (A)})

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

t_vec3			ft_vec3norm(t_vec3 v);

t_vec3			ft_vec3cross(t_vec3 a, t_vec3 b);
float			ft_vec3dot(t_vec3 a, t_vec3 b);

t_vec3			ft_vec3sub(t_vec3 a, t_vec3 b);
t_vec3			ft_vec3front(t_vec2 a);
void			ft_vec3rotate(t_vec3 *v, t_vec3 rotate);

# define _VEC3_OP(A,O,B)	(VEC3(A.x O B.x, A.y O B.y, A.z O B.z))
# define _VEC3_OP1(A,O,B)	(VEC3(A.x O B, A.y O B, A.z O B))

/*
** ========================================================================== **
** Vec4
** -
** VEC4(X, Y, Z, W)		t_vec4 constructor {X, Y, Z, W}
** VEC4_0()				t_vec4 constructor {0, 0, 0, 0}
** VEC4_1(A+)			t_vec4 constructor {A, A, A, A}
*/

struct			s_vec4
{
	float			x;
	float			y;
	float			z;
	float			w;
};

# define VEC4(X, Y, Z, W)	((t_vec4){(X), (Y), (Z), (W)})
# define VEC4_0()			((t_vec4){0.f, 0.f, 0.f, 0.f})
# define VEC4_1(A)			((t_vec4){(A), (A), (A), (A)})

/*
** ========================================================================== **
** Mat4
** -
** MAT4(...)			t_mat4 constructor
** MAT4_0()				t_mat4 0
** MAT4_I()				t_mat4 identity
*/

struct			s_mat4
{
	t_vec4			x;
	t_vec4			y;
	t_vec4			z;
	t_vec4			w;
};

# define MAT4(...)			((t_mat4){##__VA_ARGS__})

# define MAT4_0()			((t_mat4){VEC4_0(), VEC4_0(), VEC4_0(), VEC4_0()})
# define MAT4_I()			((t_mat4){MAT4_IX(),MAT4_IY(),MAT4_IZ(),MAT4_IW()})

# define REFLECT_X			(1 << 1)
# define REFLECT_Y			(1 << 2)
# define REFLECT_Z			(1 << 3)

t_mat4			ft_mat4perspective(float fov, float ratio, float f, float n);
t_mat4			ft_mat4look_at(t_vec3 pos, t_vec3 target, t_vec3 up);

void			ft_mat4translate(t_mat4 *m, t_vec3 translate);
void			ft_mat4scale(t_mat4 *m, float scale);
void			ft_mat4scale3(t_mat4 *m_a, t_vec3 scale);
void			ft_mat4shear(t_mat4 *mat, t_vec3 shear);
void			ft_mat4rotate(t_mat4 *m, t_vec3 rotate);
void			ft_mat4reflect(t_mat4 *mat, int flags);

void			ft_mat4rotate_inv(t_mat4 *mat, t_vec3 rotate);
void			ft_mat4reflect_inv(t_mat4 *mat, int flags);

t_mat4			*ft_mat4mult(t_mat4 const *a, t_mat4 const *b, t_mat4 *dst);

void			ft_mat4transpose(t_mat4 *m);

# define MAT4_IX()			((t_vec4){1.f, 0.f, 0.f, 0.f})
# define MAT4_IY()			((t_vec4){0.f, 1.f, 0.f, 0.f})
# define MAT4_IZ()			((t_vec4){0.f, 0.f, 1.f, 0.f})
# define MAT4_IW()			((t_vec4){0.f, 0.f, 0.f, 1.f})

#endif
