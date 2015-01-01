/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 22:03:57 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/14 22:03:57 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_tabini(t_tab *tab, int size)
{
	tab->data = MAL(t_byte, size * 16);
	tab->length = 0;
	tab->bytes = 0;
	tab->alloc_bytes = (tab->data == NULL) ? 0 : 16;
	tab->size = size;
}
