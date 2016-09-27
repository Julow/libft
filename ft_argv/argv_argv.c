/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 18:27:23 by jaguillo          #+#    #+#             */
/*   Updated: 2016/09/27 12:50:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/argv.h"
#include "p_argv.h"

t_sub			g_argv_opt_strerr[] = {
	[ARGV_OPT_OK] = SUBC("OK"),
	[ARGV_OPT_MISSING_VALUE] = SUBC("Missing value"),
	[ARGV_OPT_INVALID_VALUE] = SUBC("Invalid value"),
	[ARGV_OPT_OUT_OF_BOUNDS] = SUBC("Out of bounds"),
	[ARGV_OPT_UNKNOWN_OPT] = SUBC("Unknown option"),
};

static t_argv_opt const	*argv_get_opt(t_argv_opt const *opts,
							uint32_t opt_count, t_sub opt)
{
	uint32_t		i;

	i = 0;
	while (i < opt_count)
	{
		if (SUB_EQU(opts[i].name, opt))
			return (opts + i);
		i++;
	}
	return (NULL);
}

t_argv_opt_err	ft_argv_argv(t_argv *args, t_argv_opt const *opts,
					uint32_t opt_count, void *dst)
{
	t_sub				opt_str;
	t_argv_opt const	*opt;
	t_argv_state		prev_state;
	t_argv_opt_err		err;

	err = ARGV_OPT_OK;
	while (err == ARGV_OPT_OK)
	{
		prev_state = ARGV_STATE(args);
		if (!ft_argv_opt(args, &opt_str))
			break ;
		while ((opt = argv_get_opt(opts, opt_count, opt_str)) != NULL
				&& opt->type == ARGV_OPT_T_ALIAS)
			opt_str = opt->alias;
		err = (opt == NULL) ? ARGV_OPT_UNKNOWN_OPT :
				g_argv_opt[opt->type](args, opt, dst + opt->offset);
	}
	if (err != ARGV_OPT_OK)
		ARGV_RESTORE(args, prev_state);
	return (err);
}
