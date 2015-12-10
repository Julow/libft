/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:37:57 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 17:39:23 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"

char const		*ft_getenv(t_sub key)
{
	int							i;
	extern char const *const	*environ;

	i = -1;
	while (environ[++i] != NULL)
		if (ft_memcmp(environ[i], key.str, key.length) == 0
			&& environ[i][key.length] == '=')
			return (environ[i] + key.length + 1);
	return (NULL);
}
