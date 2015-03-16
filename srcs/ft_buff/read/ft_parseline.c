/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 20:13:55 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/16 23:50:56 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
