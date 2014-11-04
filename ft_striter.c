/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:23:48 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/04 14:23:49 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_striter(char *s, void (*f)(char*))
{
	size_t			i;

	i = 0;
	while (s[i] != '\0')
	{
		f(s + i);
		i++;
	}
}
