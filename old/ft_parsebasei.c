/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsebasei.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 19:14:44 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:17:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buff.h"

bool			ft_parsebasei(t_buff *buff, const char *base, uint64_t *nb)
{
	const uint32_t	base_len = ft_strlen(base);
	int				tmp;

	if ((tmp = ft_strichri(base, BG(buff))) == -1)
		return (false);
	*nb = tmp;
	buff->i++;
	while ((tmp = ft_strichri(base, BG(buff))) != -1)
	{
		*nb = (*nb) * base_len + tmp;
		buff->i++;
	}
	return (true);
}
