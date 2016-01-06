/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 19:28:14 by juloo             #+#    #+#             */
/*   Updated: 2015/04/27 22:30:48 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_bubblesort(void **tab, int length, int (*cmp)())
{
	int				i;
	void			*tmp;

	i = 1;
	while (i < length)
	{
		if (i >= 1 && cmp(tab[i - 1], tab[i]) > 0)
		{
			tmp = tab[i];
			tab[i] = tab[i - 1];
			tab[i - 1] = tmp;
			i--;
		}
		else
			i++;
	}
}
