/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_argv_t.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 18:38:16 by juloo             #+#    #+#             */
/*   Updated: 2016/09/27 13:18:32 by jaguillo         ###   ########.fr       */
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

static t_argv_opt_err	argv_opt_t_int(t_argv *args, t_argv_opt const *opt,
							void *dst)
{
	t_sub					str_value;
	int32_t					value;

	if (!ft_argv_arg(args, &str_value) || str_value.length == 0)
		return (ARGV_OPT_MISSING_VALUE);
	if (ft_subto_int(str_value, &value) != str_value.length)
		return (ARGV_OPT_INVALID_VALUE);
	if (value > opt->int_range.y || value < opt->int_range.x)
		return (ARGV_OPT_OUT_OF_BOUNDS);
	*(int32_t*)dst = value;
	return (ARGV_OPT_OK);
}

static t_argv_opt_err	argv_opt_t_uint(t_argv *args, t_argv_opt const *opt,
							void *dst)
{
	t_sub					str_value;
	uint32_t				value;

	if (!ft_argv_arg(args, &str_value) || str_value.length == 0)
		return (ARGV_OPT_MISSING_VALUE);
	if (ft_subto_uint(str_value, &value) != str_value.length)
		return (ARGV_OPT_INVALID_VALUE);
	if (value > opt->uint_range.y || value < opt->uint_range.x)
		return (ARGV_OPT_OUT_OF_BOUNDS);
	*(uint32_t*)dst = value;
	return (ARGV_OPT_OK);
}

static t_argv_opt_err	argv_opt_t_str(t_argv *args, t_argv_opt const *opt,
							void *dst)
{
	t_sub					value;

	if (!ft_argv_arg(args, &value))
		return (ARGV_OPT_MISSING_VALUE);
	if (!opt->empty_str && value.length == 0)
		return (ARGV_OPT_INVALID_VALUE);
	*(t_sub*)dst = value;
	return (ARGV_OPT_OK);
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
	[ARGV_OPT_T_INT] = &argv_opt_t_int,
	[ARGV_OPT_T_UINT] = &argv_opt_t_uint,
	[ARGV_OPT_T_STR] = &argv_opt_t_str,
	[ARGV_OPT_T_ALIAS] = NULL,
	[ARGV_OPT_T_FUNC] = &argv_opt_t_func,
};
