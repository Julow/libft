/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 22:03:15 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/14 22:03:15 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
