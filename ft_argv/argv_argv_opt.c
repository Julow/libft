/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_argv_opt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 18:56:19 by jaguillo          #+#    #+#             */
/*   Updated: 2016/09/20 19:20:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/argv.h"
#include "p_argv.h"

static t_argv_opt_err	argv_opt_int(t_sub value, void *dst)
{
	if (value.length == 0)
		return (ARGV_OPT_MISSING_VALUE);
	if (ft_subto_int(value, dst) != value.length)
		return (ARGV_OPT_INVALID_VALUE);
	return (ARGV_OPT_OK);
}

static t_argv_opt_err	argv_opt_uint(t_sub value, void *dst)
{
	if (value.length == 0)
		return (ARGV_OPT_MISSING_VALUE);
	if (ft_subto_uint(value, dst) != value.length)
		return (ARGV_OPT_INVALID_VALUE);
	return (ARGV_OPT_OK);
}

static t_argv_opt_err	argv_opt_p_uint(t_sub value, void *dst)
{
	uint32_t				uint_val;

	if (value.length == 0)
		return (ARGV_OPT_MISSING_VALUE);
	if (ft_subto_uint(value, &uint_val) != value.length || uint_val < 1)
		return (ARGV_OPT_INVALID_VALUE);
	*(uint32_t*)dst = uint_val;
	return (ARGV_OPT_OK);
}

static t_argv_opt_err	argv_opt_str(t_sub value, void *dst)
{
	*(char const**)dst = value.str;
	return (ARGV_OPT_OK);
}

static t_argv_opt_err	argv_opt_sub(t_sub value, void *dst)
{
	*(t_sub*)dst = value;
	return (ARGV_OPT_OK);
}

t_argv_opt_err			(*const g_argv_opt_value[])(t_sub, void*) = {
	[ARGV_OPT_VALUE_INT] = &argv_opt_int,
	[ARGV_OPT_VALUE_UINT] = &argv_opt_uint,
	[ARGV_OPT_VALUE_P_UINT] = &argv_opt_p_uint,
	[ARGV_OPT_VALUE_STR] = &argv_opt_str,
	[ARGV_OPT_VALUE_SUB] = &argv_opt_sub,
};
