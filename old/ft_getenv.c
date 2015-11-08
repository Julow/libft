/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 23:22:56 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/21 12:24:20 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ========================================================================== **
** ft_getenv
** ----
** Search the variable 'name' in 'env'
** and return it's value (or NULL if not found)
** ----
** If 'env' is NULL, 'environ' is used
** ----
*/

char			*ft_getenv(char const *name, char **env)
{
	int				i;
	int				name_len;
	extern char		**environ;

	name_len = ft_strlen(name);
	if (env == NULL)
		env = environ;
	i = -1;
	while (env[++i] != NULL)
		if (ft_memcmp(env[i], name, name_len) == 0 && env[i][name_len] == '=')
			return (env[i] + name_len + 1);
	return (NULL);
}
