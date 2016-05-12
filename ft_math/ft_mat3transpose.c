/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat3transpose.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 20:44:56 by juloo             #+#    #+#             */
/*   Updated: 2016/05/12 23:40:09 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math_mat3.h"

void			ft_mat3transpose(t_mat3 *m)
{
	float			tmp;
	int				i;
	int				j;

	i = -1;
	while (++i < 3)
	{
		j = i;
		while (++j < 3)
		{
			tmp = ((float*)m)[i * 3 + j];
			((float*)m)[i * 3 + j] = ((float*)m)[j * 3 + i];
			((float*)m)[j * 3 + i] = tmp;
		}
	}
}
