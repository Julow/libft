/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 12:48:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 17:52:42 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

typedef struct s_vec2		t_vec2;
typedef struct s_vec3		t_vec3;
typedef struct s_vec4		t_vec4;
typedef struct s_mat4		t_mat4;

struct			s_vec2
{
	float			x;
	float			y;
};

struct			s_vec3
{
	float			x;
	float			y;
	float			z;
};

struct			s_vec4
{
	float			x;
	float			y;
	float			z;
	float			w;
};

struct			s_mat4
{
	t_vec4			x;
	t_vec4			y;
	t_vec4			z;
	t_vec4			w;
};

# define VEC2(x,y)			((t_vec2){(x), (y)})
# define VEC3(x,y,z)		((t_vec3){(x), (y), (z)})
# define VEC4(x,y,z,w)		((t_vec4){(x), (y), (z), (w)})

# define VEC2_0()			((t_vec2){0.f, 0.f})
# define VEC3_0()			((t_vec3){0.f, 0.f, 0.f})
# define VEC4_0()			((t_vec4){0.f, 0.f, 0.f, 0.f})

# define VEC4_X()			((t_vec4){1.f, 0.f, 0.f, 0.f})
# define VEC4_Y()			((t_vec4){0.f, 1.f, 0.f, 0.f})
# define VEC4_Z()			((t_vec4){0.f, 0.f, 1.f, 0.f})
# define VEC4_W()			((t_vec4){0.f, 0.f, 0.f, 1.f})

# define MAT4(...)			((t_mat4){##__VA_ARGS__})

# define MAT4_0()			((t_mat4){VEC4_0(), VEC4_0(), VEC4_0(), VEC4_0()})
# define MAT4_I()			((t_mat4){VEC4_X(), VEC4_Y(), VEC4_Z(), VEC4_W()})

# define REFLECT_X			(1 << 1)
# define REFLECT_Y			(1 << 2)
# define REFLECT_Z			(1 << 3)

/*
** mat4 init
*/
t_mat4			ft_mat4perspective(float fov, float ratio, float f, float n);
t_mat4			ft_mat4look_at(t_vec3 pos, t_vec3 target, t_vec3 up);

/*
** mat4 transformations
*/
void			ft_mat4translate(t_mat4 *m, t_vec3 translate);
void			ft_mat4scale(t_mat4 *m, float scale);
void			ft_mat4scale3(t_mat4 *m_a, t_vec3 scale);
void			ft_mat4shear(t_mat4 *mat, t_vec3 shear);
void			ft_mat4rotate(t_mat4 *m, t_vec3 rotate);
void			ft_mat4reflect(t_mat4 *mat, int flags);

void			ft_mat4rotate_inv(t_mat4 *mat, t_vec3 rotate);
void			ft_mat4reflect_inv(t_mat4 *mat, int flags);

/*
** mat4 operations
** return 'dst'
*/
t_mat4			*ft_mat4mult(t_mat4 const *a, t_mat4 const *b, t_mat4 *dst);

void			ft_mat4transpose(t_mat4 *m);

/*
** vec3 init
*/
t_vec3			ft_vec3front(t_vec2 a);

/*
** vec3 transformations
*/
void			ft_vec3rotate(t_vec3 *v, t_vec3 rotate);

/*
** vec3 operations
*/
t_vec3			ft_vec3norm(t_vec3 v);
t_vec3			ft_vec3sub(t_vec3 a, t_vec3 b);
t_vec3			ft_vec3cross(t_vec3 a, t_vec3 b);
float			ft_vec3dot(t_vec3 a, t_vec3 b);

#endif
