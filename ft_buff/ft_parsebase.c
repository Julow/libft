/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsebase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 21:55:25 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/27 23:45:47 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_buff.h"

t_bool			ft_parsebase(t_buff *buff, const char *base, t_ulong *nb)
{
	const t_uint	base_len = ft_strlen(base);
	int				tmp;

	if ((tmp = ft_strchri(base, BG(buff))) == -1)
		return (false);
	*nb = tmp;
	buff->i++;
	while ((tmp = ft_strchri(base, BG(buff))) != -1)
	{
		*nb = (*nb) * base_len + tmp;
		buff->i++;
	}
	return (true);
}
