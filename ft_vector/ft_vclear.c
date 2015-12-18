/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vclear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 15:39:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/18 16:54:08 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_vector.h"
#include <stdlib.h>

void			ft_vclear(t_vector *v)
{
	if (v->capacity > 0)
		free(v->data);
	v->data = NULL;
	v->length = 0;
	v->capacity = 0;
}
