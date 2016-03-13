/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_vec4.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:33:27 by juloo             #+#    #+#             */
/*   Updated: 2016/03/13 22:34:26 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_VEC__H
# define MATH_VEC__H

typedef struct s_vec4		t_vec4;

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

#endif
