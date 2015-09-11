/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 01:27:04 by juloo             #+#    #+#             */
/*   Updated: 2015/09/12 01:28:29 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_path.h"

t_sub			ft_pathdir(t_sub path)
{
	int				len;

	len = path.length;
	while (--len >= 0)
		if (path.str[len] == '/'
			&& (len <= 0 || path.str[len - 1] != '\\'))
		{
			// TODO handle //
			return (SUB(path.str, len));
		}
	return (SUB(path.str, 0));
}
