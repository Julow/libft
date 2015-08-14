/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 20:13:55 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 01:58:12 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_string.h"

int				ft_parseline(t_buff *buff, t_string *dst)
{
	int				len;

	len = dst->length;
	while (!BEOF(buff))
	{
		if (BIS(buff, '\n'))
			break ;
		ft_stringaddc(dst, BR(buff));
	}
	return (dst->length - len);
}
