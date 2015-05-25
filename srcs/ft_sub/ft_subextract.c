/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subextract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 01:03:03 by juloo             #+#    #+#             */
/*   Updated: 2015/05/26 01:39:56 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_subextract
** ----
** Extract sub-strings of chars that match 'mask'
** Store subs into the array 'dst'
** Do not extract more that 'max' subs
** Extract ft_subcount subs if 'max' < 0
** ----
** Return the total of subs extracted
** ----
*/
int				ft_subextract(t_sub sub, t_sub *dst, int max, t_is mask)
{
	int				count;
	int				i;
	int				tmp;

	count = 0;
	i = 0;
	while (!IS(sub.str[i], mask) && i < sub.length)
		i++;
	while (i < sub.length && (count < max || max < 0))
	{
		tmp = i;
		while (IS(sub.str[i], mask))
			i++;
		dst[count++] = SUB(sub.str + tmp, i - tmp);
		while (!IS(sub.str[i], mask) && i < sub.length)
			i++;
	}
	return (count);
}
