/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 16:38:54 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/02 18:47:47 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/path.h"

t_sub			ft_path_split(t_sub path, t_sub *dirname)
{
	uint32_t		i;

	i = path.length;
	while (i > 0 && path.str[i - 1] != '/')
		i--;
	if (dirname != NULL)
		*dirname = SUB(path.str, (i > 1) ? i - 1 : i);
	return (SUB_FOR(path, i));
}

t_sub			ft_path_ext(t_sub path, t_sub *basename)
{
	uint32_t		i;

	path = ft_path_split(path, NULL);
	i = path.length;
	while (i > 0 && path.str[i - 1] != '.')
		i--;
	if (i <= 1)
		i = path.length;
	if (basename != NULL)
		*basename = SUB(path.str, (i < path.length) ? i - 1 : i);
	return (SUB_FOR(path, i));
}
