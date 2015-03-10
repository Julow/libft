/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 23:22:56 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/10 23:23:06 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*key_equ(char *env, const char *key)
{
	int				i;

	i = 0;
	while (env[i] != '\0' && env[i] == key[i])
		i++;
	if (key[i] == '\0' && env[i] == '=')
		return (env + i + 1);
	return (NULL);
}

char			*ft_getenv(const char *key)
{
	extern char		**environ;
	char			*tmp;
	int				i;

	i = -1;
	while (environ[++i] != NULL)
	{
		tmp = key_equ(environ[i], key);
		if (tmp != NULL)
			return (tmp);
	}
	return (NULL);
}
