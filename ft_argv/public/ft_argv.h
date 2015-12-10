/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/18 21:19:59 by juloo             #+#    #+#             */
/*   Updated: 2015/12/10 19:14:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARGV_H
# define FT_ARGV_H

# include "ft/libft.h"

typedef struct s_args		t_args;
typedef struct s_opt		t_opt;

/*
** ========================================================================== **
*/

# define FTARGS_END			(1 << 2)
# define FTARGS_LONG		(1 << 3)

struct			s_args
{
	char			**argv;
	int				argc;
	int				flags;
	int				c;
	int				i;
	char			opt[2];
};

/*
** ARGS
** ---
** Init a 't_args' struct
** ---
*/
# define ARGS(c,v)		((t_args){(v), (c), 0, 1, 1, {'\0', '\0'}})

/*
** ARGS_END
** ---
** Detect if iteration is ended for opts and args
** ---
** Return 'true' if the iteration is ended
** 'false' otherwise
** ---
*/
# define ARGS_END(a)	((a).c >= (a).argc)

/*
** ARGS_DATA
** ---
** Detect if the current option is a long option and have data
** Example: "--opt=data"
** -
** A call to 'ft_argvarg' will return 'data'
** ---
** Return 'true' if the current option is long and have data
** 'false' otherwise
** ---
*/
# define ARGS_DATA(a)	(((a).flags) & FTARGS_LONG)

/*
** ft_argvopt
** ---
** Iter over options
** -
** Example:
**  For arguments "-a" "-bcd" "--abc" "--def=x"
**  Options are: "a", "b", "c", "d", "abc", "def"
** -
** "--", "-" or any argument that do not start with '-' stop iteration
** ---
** Warning: Can write into argv for long options
** ---
** Return an option or NULL if options ended
** ---
*/
char			*ft_argvopt(t_args *args);

/*
** ft_argvarg
** ---
** Iter over arguments
** -
** Used with ft_argvopt can return the value of an option
**  ex: "-clol": ft_argvopt return "c", ft_argvarg return "lol"
**  ex: "-c" "lol": ft_argvopt return "c", ft_argvarg return "lol"
**  ex: "--lol=c": ft_argvopt return "lol", ft_argvarg return "c"
** ---
** Return an argument
** ---
*/
char			*ft_argvarg(t_args *args);

/*
** ========================================================================== **
** ft_argv
** ----
** Iter over options using ft_argvopt
** Take an array of t_opt:
**  t_opt.opt     Opt name (first arg of t_opt.f)
**  t_opt.alias   Opt name (compared with result of ft_argvopt)
**  t_opt.arg     If require a argument
**  t_opt.f       Callback(opt name, argument if t_opt.arg else NULL)
** ----
** bool			callback(void *data, t_args *args, char *opt, char *arg);
**  If the callback function return false, ft_argv stop
** ----
** Warning: An empty opt name cause an undefined behavior
** ----
** Return false if an option fail or does not exists
** true otherwise
*/

struct			s_opt
{
	char			*opt;
	char const		*alias;
	bool			arg;
	bool			(*f)();
};

bool			ft_argv(t_args *args, t_opt const *opts, int len, void *data);

/*
** Error messages
**  E_ARGV_NO      Option does not exists
**  E_ARGV_ARG     t_opt.arg is true and there is no argment
*/
# define E_ARGV_NO		"%s: -%s: unknown option\n"
# define E_ARGV_ARG		"%s: -%s: need an argument\n"

/*
** ========================================================================== **
*/

#endif
