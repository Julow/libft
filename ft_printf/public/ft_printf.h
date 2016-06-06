/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 01:05:48 by juloo             #+#    #+#             */
/*   Updated: 2016/06/06 17:18:27 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft/ft_dstr.h"
# include "ft/ft_out.h"

typedef enum e_log_level		t_log_level;

/*
** ========================================================================== **
** Formatter
** ---
** Process a string containing format sequence
** ---
** Format:
**  %[flags][width][.precision][length]format
** Sub format:
**  %[flags][width][.repeat](<format sequence>)
** -
**  flags: 0 or more characters that represent ft_out flags
**    OUT_CENTER		"^"
**    OUT_TOUPPER		"M"
**    OUT_TOLOWER		"m"
**    OUT_REVCASE		"mM" or "Mm"
**    OUT_PLUS			"+"
**    OUT_SPACE			" "
**    OUT_GROUP			"'"
**    alternate form	"#"
**    negative width	"-"
**  width: integer or '*' (width is taken from the argument list as an int)
**  precision: '.' character then integer or '*'
**  length: type
**    -		sS				dDi			oOuUxX			cC			fFeEaA
**    -		char const*		int			unsigned int	char		double
**    hh	-				char		unsigned char	-			float
**    h		-				short		unsigned short	-			float
**    ll L	wchar_t const*	long long	ull				wchar_t		long double
**    l		wchar_t const*	long		unsigned long	wchar_t		-
**    j		-				intmax_t	uintmax_t		-			-
**    t		t_sub			ptrdiff_t	ptrdiff_t		-			-
**    z		t_dstr const*	ssize_t		size_t			-			-
**    q		-				int64_t		uint64_t		-			-
**  format: one of "sSdDoOuUxXicCnpfFeE"
** ---
** TODO: implement ft_sprintf and ft_snprintf
*/

/*
** Write to fd 1 (stdout)
*/
void		ft_printf(char const *format, ...);

/*
** Write to 'fd'
*/
void		ft_dprintf(int fd, char const *format, ...);

/*
** Write to 'out'
*/
void		ft_fprintf(t_out *out, char const *format, ...);

/*
** Write to 'buff'
** Terminate with a '\0'
** Return the length
*/
uint32_t	ft_sprintf(char *buff, char const *format, ...);

/*
** Write to a new dstr
*/
t_dstr		ft_aprintf(char const *format, ...);

/*
** Append to 'str'
*/
void		ft_asprintf(t_dstr *str, char const *format, ...);

/*
** ========================================================================== **
** Logs
*/

enum		e_log_level
{
	LOG_DEBUG,
	LOG_VERBOSE,
	LOG_INFO,
	LOG_SUCCESS,
	LOG_WARNING,
	LOG_ERROR
};

void		ft_logf(t_log_level level, char const *format, ...);

void		ft_logf_set_enabled(t_log_level level, bool enabled);

/*
** ========================================================================== **
** FTOUT
** ---
** Out used by ft_printf
*/

typedef struct s_ftout		t_ftout;

struct		s_ftout
{
	t_out		out;
	int			fd;
};

extern t_ftout	g_ftout;

# define FTOUT		(&(g_ftout.out))

/*
** Flush FTOUT and change it's destination fd
*/
void		ft_out(int fd);

#endif
