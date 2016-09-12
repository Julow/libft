/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 01:19:03 by juloo             #+#    #+#             */
/*   Updated: 2016/09/12 22:38:08 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/argv.h"

static bool		argvopt_long(t_argv *argv, t_sub *opt)
{
	if (*(opt->str += 2) == '\0')
	{
		argv->i.x++;
		return (false);
	}
	while (opt->str[opt->length] != '\0' && opt->str[opt->length] != '=')
		opt->length++;
	argv->flags = _ARGV_FLAG_LONG;
	argv->i.y = 2 + opt->length;
	if (opt->str[opt->length] == '=')
	{
		argv->i.y++;
		argv->flags |= _ARGV_FLAG_VALUE;
	}
	return (true);
}

bool			ft_argv_opt(t_argv *argv, t_sub *opt)
{
	opt->length = 0;
	if (argv->flags & _ARGV_FLAG_LONG && argv->i.x < argv->argc)
		argv->i = VEC2U(argv->i.x + 1, 0);
	argv->flags = 0;
	if (argv->i.x >= argv->argc || argv->argv[argv->i.x][0] == '\0')
		return (false);
	if (*(opt->str = argv->argv[argv->i.x] + argv->i.y) == '\0'
		&& (argv->i = VEC2U(argv->i.x + 1, 0)).x >= argv->argc)
		return (false);
	if (argv->i.y == 0)
	{
		if (opt->str[0] != '-' || opt->str[1] == '\0')
			return (false);
		if (opt->str[1] == '-')
			return (argvopt_long(argv, opt));
		argv->i.y = 1;
		opt->str++;
	}
	if (opt->str[1] != '\0' || (argv->i.x + 1) < argv->argc)
		argv->flags |= _ARGV_FLAG_VALUE;
	opt->length = 1;
	argv->i.y++;
	return (true);
}
