/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 23:26:09 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/15 16:18:56 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_wchar.h"

t_uint			ft_wstrlen(wchar_t const *wstr)
{
	t_uint			i;

	if (wstr == NULL)
		return (0);
	i = 0;
	while (wstr[i] != 0)
		i++;
	return (i);
}
