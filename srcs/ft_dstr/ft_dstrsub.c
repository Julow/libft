/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 13:11:14 by jaguillo          #+#    #+#             */
/*   Updated: 2015/06/09 13:11:31 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dstr.h"

t_sub			ft_dstrsub(t_dstr *str, int from, int to)
{
	if (from < 0)
		from += str->length + 1;
	if (to < 0)
		to += str->length + 1;
	return (SUB(str->str + from, to - from));
}
