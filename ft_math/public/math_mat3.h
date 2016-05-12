/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_mat3.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 19:14:24 by juloo             #+#    #+#             */
/*   Updated: 2016/04/17 21:09:13 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_MAT3_H
# define MATH_MAT3_H

# include "ft/math_vec3.h"

typedef struct s_mat3		t_mat3;

/*
** ========================================================================== **
** Mat3
*/

struct			s_mat3
{
	t_vec3			x;
	t_vec3			y;
	t_vec3			z;
};

# define MAT3(X, Y, Z)	((t_mat3){(X), (Y), (Z)})
# define MAT3_I()		((t_mat3){{1.f,0.f,0.f},{0.f,1.f,0.f},{0.f,0.f,1.f}})

void			ft_mat3mul(t_mat3 *dst, t_mat3 const *a, t_mat3 const *b);

void			ft_mat3transpose(t_mat3 *m);

void			ft_mat3apply(t_mat3 const *m, t_vec3 *v);

#endif
