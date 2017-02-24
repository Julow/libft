/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:45:17 by jaguillo          #+#    #+#             */
/*   Updated: 2017/02/24 17:40:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERM_H
# define FT_TERM_H

# include "ft/ft_out.h"
# include "ft/libft.h"

# include <termios.h>

typedef struct s_term						t_term;
typedef enum e_term_cap						t_term_cap;

/*
** ========================================================================== **
** Termcaps
*/

/*
** Only CD and CE should be used directly
*/
enum			e_term_cap
{
	TERM_CAP_CD,
	TERM_CAP_CE,
	TERM_CAP_TI,
	TERM_CAP_TE,
	TERM_CAP_CH,
	TERM_CAP_CL,
	TERM_CAP_CM,
	TERM_CAP_HO,
	TERM_CAP_UP,
	TERM_CAP_UP_N,
	TERM_CAP_DO,
	TERM_CAP_DO_N,
	TERM_CAP_LE,
	TERM_CAP_LE_N,
	TERM_CAP_ND,
	TERM_CAP_RI_N,
	TERM_CAP_AL,
	TERM_CAP_AL_N,
	TERM_CAP_DL,
	TERM_CAP_DL_N,
	TERM_CAP_SF,
	TERM_CAP_SF_N,
	TERM_CAP_SR,
	TERM_CAP_SR_N,
	_TERM_CAP_COUNT
};

struct			s_term
{
	t_out				out;
	int					fd;
	uint32_t			scan_i;
	uint32_t			flags;
	uint32_t			width;
	uint32_t			height;
	uint32_t			content_height;
	uint32_t			cursor_x;
	uint32_t			cursor_y;
	struct termios		term_config[2];
	char const			*term_caps[_TERM_CAP_COUNT];
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
** Check if a termcap is available
*/
# define TERM_CAP_AVAILABLE(T,CAP)	((T)->term_caps[CAP][0] != '\0')

/*
** Init and update a t_term and init the termcap lib
** -
** Return NULL on error
*/
t_term			*ft_tinit(int fd, int flags);

/*
** Clear screen (or written lines if TERM_LINE is enabled)
** (automatic flush)
*/
void			ft_tclear(t_term *term);

/*
** Enable/Disable term attributes
*/
void			ft_trestore(t_term *term, bool enable);

/*
** Move the cursor
*/
void			ft_tcursor(t_term *term, uint32_t x, uint32_t y);

/*
** Insert/delete lines
** if n < 0, delete abs(n) lines
** otherwise, insert n lines
** The cursor should be at the column 0
*/
void			ft_tline(t_term *term, int32_t n);

/*
** Relative scroll
** Scroll down (y < 0) should only be used with TERM_FULLSCREEN
*/
void			ft_tscroll(t_term *term, int32_t y);

/*
** Put a termcap
*/
void			ft_tput(t_term *term, t_term_cap cap);

/*
** Put a termcap that take params
** (should not be used directly)
** Do nothing if the termcap is not available
*/
void			ft_tgoto(t_term *term, t_term_cap cap, int x, int y);

/*
** Put a raw termcap
** Allow for printing non-visible characters (ANSI sequences, termcaps, ...)
** (must not be used to put visible characters)
*/
void			ft_tput_raw(t_term *term, t_sub str);

/*
** Return the content_height
** The height of the part of the screen that is available (TERM_LINE)
** The height of the terminal (TERM_FULLSCREEN)
*/
uint32_t		ft_tcontent_height(t_term *term);

/*
** Update with and height attribute
** Must be call when receiving SIGWINCH signal
*/
void			ft_tupdate(t_term *term);

#endif
