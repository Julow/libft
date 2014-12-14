/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 22:05:38 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/14 22:05:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_tabext(t_tab *tab, int need)
{
	t_byte			*tmp;
	int				len;

	need = need * tab->size + tab->bytes;
	len = tab->alloc_bytes;
	if (need < len)
		return ;
	while (need >= len)
		len += 24 * tab->size;
	tmp = MAL(t_byte, len);
	tab->alloc_bytes = len;
	if (tab->data != NULL)
	{
		ft_memcpy(tmp, tab->data, tab->bytes);
		ft_bzero(tmp + tab->bytes, len - tab->bytes);
		free(tab->data);
	}
	else
		ft_bzero(tmp, len);
	tab->data = tmp;
}
