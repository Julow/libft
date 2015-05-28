/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subnextc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 18:47:40 by jaguillo          #+#    #+#             */
/*   Updated: 2015/05/28 22:23:37 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_subnextc
** ----
** Iter into a string using the rules of ft_subextract
** ----
** Note: Be sure that 'sub->length' is 0 before the iteration
** ----
** Return 'false' if the end of the string is reach
** 'true' otherwise
*/
t_bool			ft_subnextc(t_sub *sub, char c)
{
	int				i;

	sub->str += sub->length;
	i = 0;
	while (sub->str[i] == c && sub->str[i] != '\0')
		i++;
	sub->str += i;
	if (sub->str[0] == '\0')
	{
		sub->length = 0;
		return (false);
	}
	i = 0;
	while (sub->str[i] != c && sub->str[i] != '\0')
		i++;
	sub->length = i;
	return (true);
}
