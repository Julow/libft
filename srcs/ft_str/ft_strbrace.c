/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbrace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 01:34:49 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/30 01:40:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strbrace(const char *str, char open, char close)
{
	int				i;
	int				openned;

	i = -1;
	openned = 0;
	while (str[++i] != 0)
	{
		if (str[i] == open)
			openned++;
		else if (str[i] == close)
		{
			openned--;
			if (openned < 0)
				break ;
		}
	}
	return (i);
}
