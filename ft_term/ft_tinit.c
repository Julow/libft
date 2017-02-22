/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tinit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:48:39 by jaguillo          #+#    #+#             */
/*   Updated: 2017/02/22 18:39:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_dstr.h"
#include "ft/term.h"

#include "term_internal.h"

#include <stdlib.h>
#include <termcap.h>

/*
** termios->c_oflag &= ~(OPOST);
*/

static char		g_term_cap_names[][3] = {
	[TERM_CAP_CD] = "cd",
	[TERM_CAP_CE] = "ce",
	[TERM_CAP_TI] = "ti",
	[TERM_CAP_TE] = "te",
	[TERM_CAP_CH] = "ch",
	[TERM_CAP_CL] = "cl",
	[TERM_CAP_CM] = "cm",
	[TERM_CAP_HO] = "ho",
	[TERM_CAP_UP] = "up",
	[TERM_CAP_UP_N] = "UP",
	[TERM_CAP_DO] = "do",
	[TERM_CAP_DO_N] = "DO",
	[TERM_CAP_LE] = "le",
	[TERM_CAP_LE_N] = "LE",
	[TERM_CAP_ND] = "nd",
	[TERM_CAP_RI_N] = "RI",
	[TERM_CAP_AL] = "al",
	[TERM_CAP_AL_N] = "AL",
	[TERM_CAP_DL] = "dl",
	[TERM_CAP_DL_N] = "DL",
};

static void		ft_tmakeraw(struct termios *termios)
{
	termios->c_iflag &= ~(IGNBRK | BRKINT | PARMRK
		| IGNCR | ICRNL | ISTRIP | IXON);
	termios->c_oflag = ONLCR | OPOST;
	termios->c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
	termios->c_cflag &= ~(CSIZE | PARENB);
	termios->c_cflag |= CS8;
	termios->c_cc[VMIN] = 1;
	termios->c_cc[VTIME] = 0;
}

static bool		init_tgetent(struct termios *term_conf, int *flags)
{
	char const *const	term_name = ft_getenv(SUBC("TERM"));

	if (term_name == NULL || tgetent(NULL, term_name) <= 0)
	{
		if (tgetent(NULL, TERM_DEFAULT_TERM) <= 0)
			return (false);
		*flags |= TERM_USE_DEFAULT;
	}
	if (tcgetattr(0, term_conf) < 0)
		return (false);
	return (true);
}

static t_dstr	load_termcaps(uint32_t *offsets)
{
	t_dstr			dst;
	uint32_t		i;
	char			buff[128];
	char			*end;

	dst = DSTR0();
	i = 0;
	while (i < _TERM_CAP_COUNT)
	{
		offsets[i] = dst.length;
		end = buff;
		if (tgetstr(g_term_cap_names[i], &end) == NULL)
			continue ;
		ft_dstradd(&dst, SUB(buff, end - buff));
		i++;
	}
	return (dst);
}

static void		put_termcaps(char const **term_caps, char *dst,
					t_dstr *buff, uint32_t const *offsets)
{
	uint32_t		i;

	memcpy(dst, buff->str, buff->length);
	ft_dstrclear(buff);
	i = 0;
	while (i < _TERM_CAP_COUNT)
	{
		term_caps[i] = dst + offsets[i];
		i++;
	}
}

t_term			*ft_tinit(int fd, int flags)
{
	t_dstr			term_cap_buff;
	uint32_t		term_cap_offsets[_TERM_CAP_COUNT];
	struct termios	term_config;
	t_term			*term;

	if (!init_tgetent(&term_config, &flags))
		return (NULL);
	term_cap_buff = load_termcaps(term_cap_offsets);
	term = MALLOC(sizeof(t_term) + TERM_OUT_BUFF_SIZE + term_cap_buff.length);
	term->out = OUT(ENDOF(term), TERM_OUT_BUFF_SIZE, V(&term_out_flush));
	term->fd = fd;
	term->flags = flags;
	term->cursor_x = 0;
	term->cursor_y = 0;
	term->term_config[0] = term_config;
	term->term_config[1] = term_config;
	put_termcaps(term->term_caps, ENDOF(term) + TERM_OUT_BUFF_SIZE,
			&term_cap_buff, term_cap_offsets);
	if (flags & TERM_RAW)
		ft_tmakeraw(term->term_config);
	ft_tupdate(term);
	return (term);
}
