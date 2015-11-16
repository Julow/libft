/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 01:05:48 by juloo             #+#    #+#             */
/*   Updated: 2015/11/16 23:06:28 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_out.h"

/*
** ========================================================================== **
** Formatter
** ---
** Process a string containing format sequence
** ---
** Format:
**  %[flags][width][.precision][length]format
** Sub format:
**  %[flags][width](<format sequence>)
** -
**  flags: 0 or more characters that represent ft_out flags
**    OUT_CENTER		"^"
**    OUT_TOUPPER		"M"
**    OUT_TOLOWER		"m"
**    OUT_REVCASE		"mM" or "Mm"
**    OUT_PLUS			"+"
**    OUT_SPACE			" "
**    OUT_GROUP			"'"
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
*/

/*
** Write to fd 1 (stdout)
*/
void			ft_printf(char const *format, ...);

/*
** Write to 'fd'
*/
void			ft_dprintf(int fd, char const *format, ...);

/*
** Write to 'out'
*/
void			ft_fprintf(t_out *out, char const *format, ...);

/*
** Write to a buffer
*/
void			ft_sprintf(char *buff, char const *format, ...);
void			ft_snprintf(char *buff, uint32_t len, char const *format, ...);

/*
** ========================================================================== **
** Debug
*/

# define _DEBUG	__FILE__, __LINE__, __func__

# define DEBUG(f,...)	(ft_printf("%s:%d [%s] " f "\n", _DEBUG, ##__VA_ARGS__))
# define TRACE			(DEBUG("TRACE", NULL))

/*
** ========================================================================== **
** FTOUT
** ---
** Out used by ft_printf
*/

typedef struct s_ftout		t_ftout;

struct s_ftout
{
	t_out			out;
	int				fd;
};

extern t_ftout	g_ftout;

# define FTOUT		(&(g_ftout.out))

/*
** Flush FTOUT and change it's destination fd
*/
void			ft_out(int fd);

#endif
