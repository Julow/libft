/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:45:17 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/09 18:17:10 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERM_H
# define FT_TERM_H

# include "ft/ft_out.h"
# include "ft/libft.h"

typedef struct s_term						t_term;
typedef enum e_term_caps					t_term_caps;

/*
** ========================================================================== **
** Termcaps
*/

/*
** ?enum termcaps length-macro(TERMCAP_COUNT)
** uint32_t		id;
** char			*name;
** bool			tgoto;
** bool			tgoto0;
** up(?id?, "?name?", false, false),
** cm(?id?, "?name?", true, false),
** cap_do(?id?, "do", false, false),
** cl(?id?, "?name?", false, false),
** ch0(?id?, "?name?", false, true),
** ch(?id?, "?name?", true, false),
** cd(?id?, "?name?", false, false),
** ti(?id?, "?name?", false, false),
** te(?id?, "?name?", false, false),
*/

struct			s_evalue_termcaps
{
	uint32_t			id;
	char				*name;
	bool				tgoto;
	bool				tgoto0;
};

typedef struct s_evalue_termcaps const*		t_termcaps;

struct			s_enum_termcaps
{
	t_termcaps			up;
	t_termcaps			cm;
	t_termcaps			cap_do;
	t_termcaps			cl;
	t_termcaps			ch0;
	t_termcaps			ch;
	t_termcaps			cd;
	t_termcaps			ti;
	t_termcaps			te;
	int					length;
	t_termcaps const	*values;
};

extern struct s_enum_termcaps const		g_termcaps;

# define TERMCAP_COUNT		9

/*
** ?end
*/

struct			s_term
{
	t_out				out;
	void				*term_config;
	t_sub				termcaps[TERMCAP_COUNT];
	int					fd;
	uint32_t			flags;
	uint32_t			width;
	uint32_t			height;
	uint32_t			cursor_x;
	uint32_t			cursor_y;
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
** (automatic flush)
*/
void			ft_tcursor(t_term *term, uint32_t x, uint32_t y);

/*
** Put a termcap
** x and y are only used by termcaps with tgoto set
*/
void			ft_tput(t_term *term, t_termcaps cap, int x, int y);

/*
** Update with and height attribute
** Must be call when receiving SIGWINCH signal
*/
void			ft_tupdate(t_term *term);

#endif
