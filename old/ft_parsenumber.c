/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsenumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 19:18:36 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:17:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buff.h"

/*
** Parse an integer
** decimal/hexa/octal/binary
** hexa is case insensitive
*/

bool			ft_parsenumber(t_buff *buff, uint64_t *nb)
{
	if (BIS(buff, '0'))
	{
		if (BIS(buff, 'x'))
			return (ft_parsebasei(buff, BASE_16, nb));
		else if (BIS(buff, 'b'))
			return (ft_parsebase(buff, BASE_2, nb));
		return (ft_parsebase(buff, BASE_8, nb));
	}
	return (ft_parsebase(buff, BASE_10, nb));
}
