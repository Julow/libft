/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 15:01:01 by juloo             #+#    #+#             */
/*   Updated: 2015/12/10 19:14:52 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool			ft_issort(void **tab, int length, int (*cmp)())
{
	while (--length > 0)
		if (cmp(tab[length - 1], tab[length]) > 0)
			return (false);
	return (true);
}
