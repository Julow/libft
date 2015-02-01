/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isrange.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 00:16:57 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/01 00:18:03 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_bool	ft_isrange(int c, int from, int to)
{
	if (from <= to)
		return ((c >= from && c <= to) ? true : false);
	return ((c >= to && c <= from) ? true : false);
}
