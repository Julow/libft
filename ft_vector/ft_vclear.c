/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vclear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 15:39:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/27 23:45:22 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_vector.h"
#include <stdlib.h>

void			ft_vclear(t_vector *v)
{
	free(v->data);
	v->data = NULL;
	v->length = 0;
	v->capacity = 0;
}
