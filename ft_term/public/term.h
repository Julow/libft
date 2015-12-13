/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:45:17 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/13 18:12:25 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERM_H
# define FT_TERM_H

# include "ft/ft_out.h"
# include "ft/libft.h"

typedef struct s_term		t_term;
typedef enum e_term_caps	t_term_caps;

/*
** ========================================================================== **
** Termcaps
*/

enum		e_term_caps
{
	TERMCAP_up = 0,
	TERMCAP_do,
	TERMCAP_cl,
	TERMCAP_ch0,
	TERMCAP_ch,
	TERMCAP_cd,
	TERMCAP_ti,
	TERMCAP_te,
	_TERMCAP_COUNT
};

struct		s_term
{
	t_out			out;
	void			*term_config;
	t_sub			termcaps[_TERMCAP_COUNT];
	int				fd;
	uint32_t		flags;
	uint32_t		width;
	uint32_t		height;
	uint32_t		line_count;
	uint32_t		line_offset;
};

# define TERM_DEFAULT_TERM	"xterm"

# define TERM_OUT_BUFF_SIZE	512

/*
** Enable line count
** ft_tclear clear only written lines
*/
# define TERM_LINE			(1 << 1)

/*
** Use terminal fullscreen mode ('ti')
*/
# define TERM_FULLSCREEN	(1 << 2)

/*
** Terminal raw mode, required to use ft_getchr
*/
# define TERM_RAW			(1 << 3)

/*
** Set at init if $TERM is invalid and TERM_DEFAULT_TERM is used instead
*/
# define TERM_USE_DEFAULT	(1 << 4)

/*
** Init and update a t_term and init the termcap lib
** -
** Return NULL on error
*/
t_term		*ft_tinit(int fd, int flags);

/*
** Clear screen (or written lines if TERM_LINE is enabled)
*/
void		ft_tclear(t_term *term);

/*
** Enable/Disable term attributes
*/
void		ft_trestore(t_term *term, bool enable);

/*
** Move the cursor relatively
*/
void		ft_tcursor(t_term *term, int x, int y);

/*
** Put a termcap
*/
void		ft_tgoto(t_term *term, t_term_caps cap, int x, int y);
void		ft_tput(t_term *term, t_term_caps cap);

/*
** Update with and height attribute
** Must be call when receiving SIGWINCH signal
*/
void		ft_tupdate(t_term *term);

#endif
