/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 23:18:37 by juloo             #+#    #+#             */
/*   Updated: 2015/09/21 12:24:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <errno.h>

/*
** ========================================================================== **
** ft_exec
** ----
** Try to execute a command
** ----
** The command name is argv[0]
** Search in the PATHs (except if the cmd contains '/')
** If 'env' is NULL, the 'environ' variable is used
** ----
** Never return if success
** Return errno if fail
*/

static int		try_exec(t_sub path, t_sub cmd, char **argv, char **env)
{
	char			cmd_path[path.length + cmd.length + 2];

	ft_memcpy(cmd_path, path.str, path.length);
	ft_memcpy(cmd_path + path.length + 1, cmd.str, cmd.length);
	cmd_path[path.length] = '/';
	cmd_path[path.length + cmd.length + 1] = '\0';
	if (path.length == 0)
		execve(cmd_path + 1, argv, env);
	else
		execve(cmd_path, argv, env);
	return (errno);
}

int				ft_exec(char **argv, char **env)
{
	t_sub			path;
	int				cmd_len;
	int				err;
	extern char		**environ;

	if (env == NULL)
		env = environ;
	if (argv[0] == NULL || (path.str = ft_getenv("PATH", env)) == NULL)
		return (ENOENT);
	path.length = 0;
	cmd_len = ft_strlen(argv[0]);
	if (ft_strchr(argv[0], '/') != NULL)
		return (try_exec(path, SUB(argv[0], cmd_len), argv, env));
	err = ENOENT;
	while (ft_subnextc(&path, ':'))
	{
		try_exec(path, SUB(argv[0], cmd_len), argv, env);
		if (err == ENOENT)
			err = errno;
	}
	return (err);
}
