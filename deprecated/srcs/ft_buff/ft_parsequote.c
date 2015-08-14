/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsequote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 01:27:11 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 01:58:25 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_string.h"

t_bool			ft_parsequote(t_buff *buff, t_string *dst)
{
	char			quote;

	if (BIS(buff, '"'))
		quote = '"';
	else if (BIS(buff, '\''))
		quote = '\'';
	else
		return (false);
	while (!BEOF(buff))
	{
		if (BIS(buff, '\\'))
			ft_stringaddc(dst, ft_unescape(BR(buff)));
		else if (BIS(buff, quote))
			return (true);
		else
			ft_stringaddc(dst, BR(buff));
	}
	return (false);
}
