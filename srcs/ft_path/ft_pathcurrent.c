/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathcurrent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 01:27:04 by juloo             #+#    #+#             */
/*   Updated: 2015/09/12 01:29:01 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_path.h"
#include <unistd.h>

t_bool			ft_pathcurrent(t_dstr *dst)
{
	char			*path;

	if ((path = getcwd(NULL, 0)) == NULL)
		return (false);
	ft_dstrdestroy(dst);
	dst->str = path;
	dst->length = ft_strlen(path);
	dst->capacity = dst->length;
	return (true);
}
