/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_escape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 01:28:18 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/03 01:28:56 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*g_escapes = "a\ab\bf\fn\nr\rt\tv\v0\0\0";

char			ft_escape(char c)
{
	char			*escs;

	escs = g_escapes + 1;
	while (*escs != c)
	{
		if (*escs == '\0')
			return (c);
		escs += 2;
	}
	return (escs[-1]);
}
