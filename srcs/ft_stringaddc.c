/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringaddc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 18:03:59 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/15 18:04:00 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool			ft_stringaddc(t_string *str, char c)
{
	if (!ft_stringext(str, 1))
		return (FALSE);
	str->content[str->length] = c;
	str->length++;
	return (TRUE);
}
