/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 12:30:18 by juloo             #+#    #+#             */
/*   Updated: 2015/05/26 00:56:30 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool			ft_tabiter(t_tab *tab, t_bool (*f)(), void *data)
{
	const void		*max = tab->data + (tab->length * tab->size);
	void			*iter;

	iter = tab->data;
	while (iter < max)
	{
		if (!f(iter, data))
			return (false);
		iter += tab->size;
	}
	return (true);
}
