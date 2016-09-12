/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 00:55:44 by juloo             #+#    #+#             */
/*   Updated: 2016/09/12 21:19:07 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGV_H
# define ARGV_H

# include "ft/libft.h"

typedef struct s_argv		t_argv;

/*
** ========================================================================== **
** Argv parser
*/

struct			s_argv
{
	char const *const	*argv;
	uint32_t			argc;
	uint32_t			flags;
	t_vec2u				i;
};

/*
** Init a argv object
*/
# define ARGV(ARGC, ARGV)		((t_argv){ARGV, ARGC, 0, VEC2U(1, 0)})

/*
** Check if the last option has a value
** Example: "-avalue", "-a value", "--a="
*/
# define ARGV_HAS_VALUE(ARGV)	((bool)((ARGV)->flags & _ARGV_FLAG_VALUE))

/*
** Check if the last option is a long option
** Example: "--option"
*/
# define ARGV_IS_LONG(ARGV)		((bool)((ARGV)->flags & _ARGV_FLAG_LONG))

/*
** Check if the last argument has been read
*/
# define ARGV_END(ARGV)			((bool)(((ARGV)->i.x >= (ARGV)->argc)))

/*
** Look for the next option
** Write it into 'opt'
** Return false at the end of the arguments, on a non-option argument or "--"
** Return true on success
*/
bool			ft_argv_opt(t_argv *argv, t_sub *opt);

/*
** Look for the next argument
**  or last option's value if ARGV_HAS_VALUE(argv) is true
** Write it into 'arg'
** Return true on success, false if there is no more argument
*/
bool			ft_argv_arg(t_argv *argv, t_sub *arg);

/*
** -
*/

# define _ARGV_FLAG_VALUE		(1 << 0)
# define _ARGV_FLAG_LONG		(1 << 1)

#endif
