/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 00:55:44 by juloo             #+#    #+#             */
/*   Updated: 2016/09/25 18:17:28 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGV_H
# define ARGV_H

# include "ft/libft.h"

typedef struct s_argv		t_argv;

typedef struct s_argv_opt		t_argv_opt;
typedef enum e_argv_opt_err		t_argv_opt_err;

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
# define ARGV(ARGC, ARGV)		((t_argv){V(ARGV), ARGC, 0, VEC2U(1, 0)})

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
** ========================================================================== **
** Improved argv parser
*/

/*
** Used to declare accepted options
** -
** name				=> Option name
** type				=> Type of option
** 		ARGV_OPT_T_FLAG		=> The option put (OR) a flag
** 		ARGV_OPT_T_SET		=> The option set a value (uint32_t)
** 		ARGV_OPT_T_VALUE	=> The option parse a value
** 		ARGV_OPT_T_ALIAS	=> Alias to an other option
** 		ARGV_OPT_T_FUNC		=> The option call a custom callback
** (ARGV_OPT_FLAG) flag			=> flag value
** (ARGV_OPT_VALUE) value_type	=> type of the value to parse
** 		ARGV_OPT_VALUE_INT			=> any int					(int32_t)
** 		ARGV_OPT_VALUE_UINT			=> any int >= 0				(uint32_t)
** 		ARGV_OPT_VALUE_P_UINT		=> any int >= 1				(uint32_t)
** 		ARGV_OPT_VALUE_STR			=> plain string				(t_sub)
** 		ARGV_OPT_VALUE_P_STR		=> plain string (non-empty)	(t_sub)
** (ARGV_OPT_ALIAS) alias		=> aliased option name
** (ARGV_OPT_FUNC) func			=> callback
** offset			=> Destination offset (where the value is write)
** -
** ARGV_OPT_FLAG(NAME, FLAG, OFFSET)	Declare a flag option
** ARGV_OPT_VALUE(NAME, FLAG, OFFSET)	Declare a value option
** ARGV_OPT_ALIAS(NAME, OPT)			Declare an alias to the option 'OPT'
** ARGV_OPT_FUNC(NAME, FUNC, OFFSET)	Declare an option with callback
*/

struct			s_argv_opt
{
	t_sub			name;
	enum {
		ARGV_OPT_T_FLAG,
		ARGV_OPT_T_SET,
		ARGV_OPT_T_VALUE,
		ARGV_OPT_T_ALIAS,
		ARGV_OPT_T_FUNC,
	}				type;
	union {
		uint32_t		flag;
		uint32_t		set;
		enum {
			ARGV_OPT_VALUE_INT,
			ARGV_OPT_VALUE_UINT,
			ARGV_OPT_VALUE_P_UINT,
			ARGV_OPT_VALUE_STR,
			ARGV_OPT_VALUE_P_STR,
		}				value_type;
		t_sub			alias;
		t_argv_opt_err	(*func)(t_argv*, void*);
	};
	uint32_t		offset;
};

# define ARGV_OPT_FLAG(N,F,O)	_ARGV_OPT(N, FLAG, .flag=(F), O)
# define ARGV_OPT_SET(N,V,O)	_ARGV_OPT(N, SET, .set=(V), O)
# define ARGV_OPT_VALUE(N,T,O)	_ARGV_OPT(N, VALUE, .value_type=ARGV_OPT_VALUE_##T, O)
# define ARGV_OPT_ALIAS(N,A)	_ARGV_OPT(N, ALIAS, .alias=SUBC(A), 0)
# define ARGV_OPT_FUNC(N,F,O)	_ARGV_OPT(N, FUNC, .func=V(F), O)

enum			e_argv_opt_err
{
	ARGV_OPT_OK = 0,
	ARGV_OPT_MISSING_VALUE,
	ARGV_OPT_INVALID_VALUE,
	ARGV_OPT_UNKNOWN_OPT,
};

/*
** Parse options
** -
** Option are parsed respecting their declaration (t_argv_opt)
** Their value are written to 'dst' at the corresponding offset
** -
** Stop on error or at the end of options (like ft_argv_opt)
** -
** On error, return the corresponding t_argv_opt_err value,
** 	the next argument (ft_argv_arg) is set to the option that caused the error
** On success, return ARGV_OPT_OK
*/
t_argv_opt_err	ft_argv_argv(t_argv *args, t_argv_opt const *opts,
					uint32_t opt_count, void *dst);

/*
** Map error (t_argv_opt_err) to error string
*/
extern t_sub	g_argv_opt_strerr[];

/*
** -
*/

# define _ARGV_OPT(N,T,V,O)		{SUBC(N), ARGV_OPT_T_##T, {V}, (O)}
# define _ARGV_FLAG_VALUE		(1 << 0)
# define _ARGV_FLAG_LONG		(1 << 1)

#endif
