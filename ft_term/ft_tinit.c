/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tinit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:48:39 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:24:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/term.h"
#include "ft/ft_str_out.h"
#include "term_internal.h"
#include <stdlib.h>
#include <termios.h>
#include <termcap.h>

/*
** termios->c_oflag &= ~(OPOST);
*/

static char *const	g_termcap_names[_TERMCAP_COUNT] = {
	[TERMCAP_up] = "up",
	[TERMCAP_cl] = "cl",
	[TERMCAP_cd] = "cd",
	[TERMCAP_ti] = "ti",
	[TERMCAP_te] = "te",
};

static char *const	g_termcap_names0[_TERMCAP_COUNT] = {
	[TERMCAP_ch0] = "ch",
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

static void		load_termcaps(t_str_out *termcaps)
{
	uint32_t		i;

	*termcaps = STR_OUT();
	i = 0;
	while (i < _TERMCAP_COUNT)
	{
		if (g_termcap_names[i] != NULL)
			ft_putstr(termcaps, tgetstr(g_termcap_names[i], NULL), -1);
		else if (g_termcap_names0[i] != NULL)
			ft_putstr(termcaps,
				tgoto(tgetstr(g_termcap_names0[i], NULL), 0, 0), -1);
		ft_putchar(termcaps, '\0');
		i++;
	}
}

static void		put_termcaps(t_sub *termcaps, char *dst, t_str_out *str)
{
	uint32_t		i;
	uint32_t		last;

	i = 0;
	ft_memcpy(dst, str->buff, str->buff_i);
	last = 0;
	while (i < _TERMCAP_COUNT)
	{
		termcaps[i].str = dst + last;
		termcaps[i].length = ft_strlen(dst + last);
		last += termcaps[i].length + 1;
		i++;
	}
	ft_str_out_clear(str);
}

t_term			*ft_tinit(int fd, int flags)
{
	t_str_out		termcaps;
	struct termios	term_config;
	t_term			*term;

	if (!init_tgetent(&term_config, &flags))
		return (NULL);
	load_termcaps(&termcaps);
	term = ft_emalloc(sizeof(t_term)
			+ TERM_OUT_BUFF_SIZE + S(struct termios, 2) + termcaps.buff_i);
	term->out = OUT(V(term) + sizeof(t_term), TERM_OUT_BUFF_SIZE,
		(void*)&term_out_flush);
	term->term_config = V(term) + sizeof(t_term) + TERM_OUT_BUFF_SIZE;
	ft_memcpy(term->term_config, &term_config, sizeof(struct termios));
	ft_memcpy(term->term_config + sizeof(struct termios),
		&term_config, sizeof(struct termios));
	put_termcaps(term->termcaps, V(term) + sizeof(t_term) + TERM_OUT_BUFF_SIZE
		+ S(struct termios, 2), &termcaps);
	term->fd = fd;
	term->flags = flags;
	term->line_count = 0;
	if (flags & TERM_RAW)
		ft_tmakeraw(term->term_config);
	ft_tupdate(term);
	return (term);
}
