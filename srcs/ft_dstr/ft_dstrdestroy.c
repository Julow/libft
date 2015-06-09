/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstrdestroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 14:07:58 by jaguillo          #+#    #+#             */
/*   Updated: 2015/06/09 14:09:44 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dstr.h"
#include <stdlib.h>

void			ft_dstrdestroy(t_dstr *str)
{
	if (str->capacity > 0)
		free(str->str);
	str->capacity = 0;
	str->length = 0;
	str->str = "";
}
