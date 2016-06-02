/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 01:18:47 by juloo             #+#    #+#             */
/*   Updated: 2016/06/02 19:04:03 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/argv.h"

bool			ft_argv_arg(t_argv *argv, t_sub *arg)
{
	while (argv->i.x < argv->argc)
	{
		arg->str = argv->argv[argv->i.x] + argv->i.y;
		argv->i = VEC2U(argv->i.x + 1, 0);
		if (arg->str[0] == '\0')
			continue ;
		argv->flags = 0;
		arg->length = ft_strlen(arg->str);
		return (true);
	}
	argv->flags = 0;
	arg->length = 0;
	return (false);
}
