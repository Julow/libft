/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:45:17 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/27 23:45:24 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERM_H
# define FT_TERM_H

# include "ft/libft.h"
# include <termios.h>
# include <termcap.h>

/*
** ========================================================================== **
** Termcaps utils
** -
** Warning: -ltermcap is needed to use theses functions
*/

# define DEFAULT_TERM	"xterm"

# define TPS(s)			PS(tgetstr((s), NULL))

typedef struct	s_term
{
	char			*name;
	struct termios	save;
	struct termios	termios;
	int				width;
	int				height;
}				t_term;

/*
** ft_getchr
** -
** Read and return a char from stdin
** -
** See keys below
*/
int				ft_getchr(void);

/*
** ft_tinit
** -
** Init a t_term struct and the termcap lib
*/
t_bool			ft_tinit(t_term *term);

/*
** ft_tupdate
** -
** Update with and height attribute
*/
void			ft_tupdate(t_term *term);

/*
** ft_trestore
** -
** Enable/Disable term attributes
*/
void			ft_trestore(t_term *term, t_bool enable);

/*
** ft_tmakeraw
** ----
** Like cfmakeraw
*/
void			ft_tmakeraw(t_term *term);

#endif
