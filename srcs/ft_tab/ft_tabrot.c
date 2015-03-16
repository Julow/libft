/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 19:46:41 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/16 22:38:54 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		tabrot(t_tab *tab, int rot)
{
	const int		len = ft_abs(rot %= tab->length) * tab->size;
	t_byte			tmp[len];

	if (rot < 0)
	{
		ft_memcpy(tmp, tab->data, len);
		ft_memmove(tab->data, tab->data + len, tab->bytes - len);
		ft_memcpy(tab->data + tab->bytes - len, tmp, len);
	}
	else
	{
		ft_memcpy(tmp, tab->data + tab->bytes - len, len);
		ft_memmove(tab->data + len, tab->data, tab->bytes - len);
		ft_memcpy(tab->data, tmp, len);
	}
}

void			ft_tabrot(t_tab *tab, int rot)
{
	if (rot != 0 && tab->length > 0)
		tabrot(tab, rot);
}
