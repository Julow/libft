/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 01:27:04 by juloo             #+#    #+#             */
/*   Updated: 2015/09/12 01:28:34 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_path.h"

t_sub			ft_pathfile(t_sub path)
{
	int				len;

	len = path.length;
	while (--len >= 0)
		if (path.str[len] == '/'
			&& (len <= 0 || path.str[len - 1] != '\\'))
			return (SUB(path.str + len + 1, path.length - len));
	return (path);
}
