/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strskip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 23:08:15 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/30 23:08:15 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_uint			ft_strskip(const char *str, const char *skip)
{
	t_uint			i;

	i = 0;
	while (ft_strchr(skip, str[i]) != NULL)
		i++;
	return (i);
}
