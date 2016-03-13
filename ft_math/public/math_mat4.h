/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_mat4.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:34:18 by juloo             #+#    #+#             */
/*   Updated: 2016/03/13 22:34:56 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_MAT__H
# define MATH_MAT__H

# include "math_vec3.h"
# include "math_vec4.h"

typedef struct s_mat4		t_mat4;

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

/*
** -
*/

# define MAT4_IX()			((t_vec4){1.f, 0.f, 0.f, 0.f})
# define MAT4_IY()			((t_vec4){0.f, 1.f, 0.f, 0.f})
# define MAT4_IZ()			((t_vec4){0.f, 0.f, 1.f, 0.f})
# define MAT4_IW()			((t_vec4){0.f, 0.f, 0.f, 1.f})

#endif
