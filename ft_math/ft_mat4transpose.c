/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4transpose.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/09 17:21:47 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/13 22:36:33 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math_mat4.h"

void			ft_mat4transpose(t_mat4 *m)
{
	float			tmp;
	int				i;
	int				j;

	i = -1;
	while (++i < 4)
	{
		j = i;
		while (++j < 4)
		{
			tmp = ((float*)m)[i * 4 + j];
			((float*)m)[i * 4 + j] = ((float*)m)[j * 4 + i];
			((float*)m)[j * 4 + i] = tmp;
		}
	}
}
