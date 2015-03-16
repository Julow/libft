/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:45:17 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/16 16:51:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERM_H
# define FT_TERM_H

# include "libft.h"
# include <termios.h>
# include <termcap.h>

/*
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
	t_bool			save_am;
	int				width;
	int				height;
}				t_term;

int				ft_getchr(void);

t_bool			ft_tinit(t_term *term);
void			ft_tupdate(t_term *term);
void			ft_trestore(t_term *term);

/*
** Keys
** -
** Return value of term_getchr()
** -
** Ascii chars have their own value as key
*/

# define KEY_ASCII(c)	(c)

# define KEY_ESC		27
# define KEY_BACK		127
# define KEY_DELETE		2117294875
# define KEY_RETURN		10
# define KEY_END		4607771

# define KEY_UP			4283163
# define KEY_LEFT		4479771
# define KEY_RIGHT		4414235
# define KEY_DOWN		4348699

# define KEY_CTRL_A		1
# define KEY_CTRL_E		5

#endif
