/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsenumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 19:18:36 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/17 00:02:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Parse an integer
** decimal/hexa/octal/binary
** hexa is case insensitive
*/
t_bool			ft_parsenumber(t_buff *buff, t_ulong *nb)
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
