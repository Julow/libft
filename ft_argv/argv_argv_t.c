/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_argv_t.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 18:38:16 by juloo             #+#    #+#             */
/*   Updated: 2016/09/25 23:30:38 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_argv.h"

static t_argv_opt_err	argv_opt_t_flag(t_argv *args, t_argv_opt const *opt,
							void *dst)
{
	*(uint32_t*)(dst) |= opt->flag;
	return (ARGV_OPT_OK);
	(void)args;
}

static t_argv_opt_err	argv_opt_t_set(t_argv *args, t_argv_opt const *opt,
							void *dst)
{
	*(uint32_t*)(dst) = opt->set;
	return (ARGV_OPT_OK);
	(void)args;
}

static t_argv_opt_err	argv_opt_t_value(t_argv *args, t_argv_opt const *opt,
							void *dst)
{
	t_sub					value;

	if (!ft_argv_arg(args, &value))
		return (ARGV_OPT_MISSING_VALUE);
	return (g_argv_opt_value[opt->value_type](value, dst));
}

static t_argv_opt_err	argv_opt_t_func(t_argv *args, t_argv_opt const *opt,
							void *dst)
{
	return (opt->func(args, dst));
}

t_argv_opt_err			(*const g_argv_opt[])(t_argv *args,
							t_argv_opt const *opt, void *dst) = {
	[ARGV_OPT_T_FLAG] = &argv_opt_t_flag,
	[ARGV_OPT_T_SET] = &argv_opt_t_set,
	[ARGV_OPT_T_VALUE] = &argv_opt_t_value,
	[ARGV_OPT_T_ALIAS] = NULL,
	[ARGV_OPT_T_FUNC] = &argv_opt_t_func,
};
