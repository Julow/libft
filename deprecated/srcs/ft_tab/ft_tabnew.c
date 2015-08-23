/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 22:03:15 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/23 15:54:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tab.h"
#include <stdlib.h>

t_tab			*ft_tabnew(int size)
{
	t_tab			*tab;

	tab = MAL1(t_tab);
	if (tab == NULL)
		return (NULL);
	ft_tabini(tab, size);
	return (tab);
}
