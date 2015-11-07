/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rnext.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 20:59:13 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/21 12:25:31 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rmatch.h"

/*
** ft_rnext
** ---
** Take the result of ft_rfind and find the next result
** The param 'pattern' does not need to be exactly the same
** ---
** Return ft_rfind
** ---
*/

t_bool			ft_rnext(t_sub *last, const char *pattern)
{
	return (ft_rfind(last, last->str + last->length, pattern));
}
