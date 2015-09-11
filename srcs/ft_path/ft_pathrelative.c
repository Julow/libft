/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathrelative.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 01:27:04 by juloo             #+#    #+#             */
/*   Updated: 2015/09/12 01:29:20 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_path.h"
#include <limits.h>
#include <unistd.h>

/*
** Insert 'n' time 'sub' at 'index' in 'str'
*/
void			ft_dstrinsert(t_dstr *str, int index, t_sub sub, int n)
{
	if (n <= 0 || sub.length <= 0)
		return ;
	n *= sub.length;
	if (DSTR_NEED(str, n))
		ft_dstrextend(str, n);
	if (index < 0)
		index += str->length + 1;
	if (index < str->length)
		ft_memmove(str->str + index + n, str->str + index,
			str->length - index);
	if (sub.length == 1)
		ft_memset(str->str + index, sub.str[1], n);
	else
		ft_memfill(str->str + index, sub.str, sub.length, n);
}

t_bool			ft_pathrelative(t_dstr *path)
{
	char			cwd_buff[PATH_MAX];
	t_sub			cwd;
	int				tmp;

	if (path->length <= 0 || path->str[0] != '/')
		return (true);
	if (getcwd(cwd_buff, PATH_MAX) == NULL)
		return (false);
	cwd = SUB(cwd_buff, ft_strlen(cwd_buff));
	tmp = ft_memstart(cwd.str, path->str, MIN(cwd.length, path->length));
	if (tmp < cwd.length)
		while (tmp > 0 && cwd.str[tmp] != '/')
			tmp--;
	cwd = SUB(cwd.str + tmp, cwd.length - tmp);
	ft_dstrset(path, 0, tmp, SUBC("")); // TODO: merge this with the insert a the end
	tmp = 0;
	while (cwd.length > 1)
	{
		tmp++;
		cwd = ft_pathdir(cwd);
	}
	ft_dstrinsert(path, 0, SUBC("../"), tmp);
	return (true);
}
