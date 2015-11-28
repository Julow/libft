/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstrclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 14:07:58 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/27 23:44:42 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_dstr.h"
#include <stdlib.h>

void			ft_dstrclear(t_dstr *str)
{
	if (str->capacity > 0)
		free(str->str);
	*str = DSTR0();
}
