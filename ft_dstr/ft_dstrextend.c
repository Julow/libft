/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstrextend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 13:15:06 by jaguillo          #+#    #+#             */
/*   Updated: 2016/01/18 18:29:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_dstr.h"
#include <stdlib.h>

void			ft_dstrextend(t_dstr *str, uint32_t need)
{
	uint32_t		capacity;
	char			*tmp;

	capacity = MAX(str->capacity, DSTR_MIN);
	need += str->capacity;
	while (capacity < need)
		capacity *= 2;
	if (capacity <= str->capacity)
		return ;
	tmp = MAL(char, capacity + 1);
	ft_memcpy(tmp, str->str, str->length);
	tmp[str->length] = '\0';
	if (str->capacity > 0)
		free(str->str);
	str->str = tmp;
	str->capacity = capacity;
}
