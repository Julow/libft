/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imageclonekil.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/20 15:08:51 by juloo             #+#    #+#             */
/*   Updated: 2015/09/17 16:54:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_draw.h"
#include <stdlib.h>

void			ft_imageclonekil(t_image *clone)
{
	free(clone->data);
	free(clone);
}
