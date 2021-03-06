/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unescape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 01:28:49 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/27 23:46:04 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"

char			ft_unescape(char c)
{
	extern char		*g_escapes;
	char			*escs;

	escs = g_escapes;
	while (*escs != '\0')
	{
		if (*escs == c)
			return (escs[1]);
		escs += 2;
	}
	return (c);
}
