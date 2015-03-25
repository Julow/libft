/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsebasei.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 19:14:44 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/25 18:03:57 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool			ft_parsebasei(t_buff *buff, const char *base, t_ulong *nb)
{
	const t_uint	base_len = ft_strlen(base);
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
