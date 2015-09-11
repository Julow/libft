/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathabsolute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 01:27:04 by juloo             #+#    #+#             */
/*   Updated: 2015/09/12 01:29:07 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_path.h"
#include <limits.h>
#include <unistd.h>

t_bool			ft_pathabsolute(t_dstr *path)
{
	char			cwd[PATH_MAX];
	int				cwd_len;

	if (path->length > 0 && path->str[0] == '/')
		return (true);
	if (getcwd(cwd, PATH_MAX) == NULL)
		return (false);
	cwd_len = ft_strlen(cwd);
	cwd[cwd_len++] = '/';
	ft_dstrset(path, 0, 0, SUB(cwd, cwd_len));
	return (true);
}
