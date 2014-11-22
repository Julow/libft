/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringaddcn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 18:59:32 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/22 18:59:34 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool			ft_stringaddcn(t_string *str, char c, int n)
{
	ft_stringext(str, n);
	while (--n >= 0)
	{
		if (!ft_stringaddc(str, c))
			return (FALSE);
	}
	return (TRUE);
}
