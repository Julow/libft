/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 15:01:01 by juloo             #+#    #+#             */
/*   Updated: 2015/04/27 15:31:56 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool			ft_issort(void **tab, int length, int (*cmp)())
{
	while (--length > 0)
		if (cmp(tab[length - 1], tab[length]) > 0)
			return (false);
	return (true);
}
