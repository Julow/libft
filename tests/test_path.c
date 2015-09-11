/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 16:04:55 by juloo             #+#    #+#             */
/*   Updated: 2015/09/12 01:28:56 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_path.h"

int				main(int argc, char **argv)
{
	t_dstr			path;
	t_sub			file;
	t_sub			dir;

	if (argc <= 2)
		return (ft_fdprintf(2, "Not enougth argument\n"), 1);
	path = ft_dstr(argv[1], ft_strlen(argv[1]));
	ft_pathappend(&path, ft_sub(argv[2], 0, -1));
	file = ft_pathfile(SUB(path.str, path.length));
	dir = ft_pathdir(SUB(path.str, path.length));
	ft_printf("%-25s %.*s %.*s%>50 ", path.str,
		dir.length, dir.str, file.length, file.str);
	ft_pathabsolute(&path);
	ft_printf("abs: %-60s ", path.str);
	ft_pathrelative(&path);
	ft_printf("rel: %-30s", path.str);
	ft_dstrset(&path, 0, -1, ft_sub(argv[1], 0, -1));
	ft_pathappend(&path, ft_sub(argv[2], 0, -1));
	ft_pathclean(&path);
	ft_printf("clean: %s", path.str);
	ft_printf("\n");
	return (0);
}
