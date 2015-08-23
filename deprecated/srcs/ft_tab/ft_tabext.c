/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 22:05:38 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/23 15:54:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tab.h"
#include <stdlib.h>

t_bool			ft_tabext(t_tab *tab, int need)
{
	t_byte			*tmp;
	int				len;

	need = need * tab->size + tab->bytes;
	len = tab->alloc_bytes;
	if (need < len)
		return (true);
	while (need >= len)
		len += TAB_CHUNK * tab->size;
	if ((tmp = MAL(t_byte, len)) == NULL)
		return (false);
	tab->alloc_bytes = len;
	if (tab->data != NULL)
	{
		ft_memcpy(tmp, tab->data, tab->bytes);
		free(tab->data);
	}
	tab->data = tmp;
	return (true);
}
