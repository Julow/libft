/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathclean.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 01:27:04 by juloo             #+#    #+#             */
/*   Updated: 2015/09/13 18:21:48 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_path.h"

static t_bool	clean_back(t_dstr const *path, t_sub dir, int *i)
{
	int				tmp;

	if (dir.length >= 1 && dir.str[0] == '.')
	{
		if (dir.length == 2 && dir.str[1] == '.' && dir.str > path->str)
		{
			tmp = *i;
			while (tmp > ((path->str[0] == '/') ? 1 : 0)
				&& path->str[--tmp - 1] != '/')
				;
			if ((*i - tmp) == 2 && ft_memcmp(path->str + tmp, "..", 2) == 0)
				return (false);
			*i = tmp;
			return (true);
		}
		return ((dir.length == 1) ? true : false);
	}
	return (false);
}

void			ft_pathclean(t_dstr *path)
{
	char const		*const end = path->str + path->length;
	t_sub			dir;
	int				i;

	dir = SUB(path->str, 0);
	i = 0;
	while (dir.str < end)
	{
		dir.length = 0;
		while ((dir.str + dir.length) < end && dir.str[dir.length] != '/')
			dir.length++;
		if (!clean_back(path, dir, &i))
		{
			ft_memmove(path->str + i, dir.str, dir.length);
			i += dir.length;
			path->str[i++] = '/';
		}
		dir.str += dir.length;
		while (dir.str < end && dir.str[0] == '/')
			dir.str++;
	}
	if (i > 1)
		i--;
	path->str[i] = '\0';
	path->length = i;
}
