/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getkey.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:58:48 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 16:47:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/getkey.h"
#include "term_internal.h"
#include <unistd.h>

// #define GETKEY_DEBUG
#ifdef GETKEY_DEBUG
# define DEBUG(...)		ft_dprintf(2, ##__VA_ARGS__)
#else
# define DEBUG(...)		VOID
#endif

static t_seq_end const	g_seq_ends[] = {
	{'A', KEY_UP, 0},
	{'B', KEY_DOWN, 0},
	{'C', KEY_RIGHT, 0},
	{'D', KEY_LEFT, 0},
	{'H', KEY_HOME, 0},
	{'F', KEY_END, 0},
	{'P', KEY_F1, 0},
	{'Q', KEY_F2, 0},
	{'R', KEY_F3, 0},
	{'S', KEY_F4, 0},
	{'Z', '\t', KEY_MOD_SHIFT},
	{3, KEY_DELETE, 0},
	{5, KEY_PAGEUP, 0},
	{6, KEY_PAGEDOWN, 0},
};

static char		next_char(int fd)
{
	fd_set			fdr;
	char			c;

	FD_ZERO(&fdr);
	FD_SET(fd, &fdr);
	if (select(fd + 1, &fdr, NULL, NULL, &(struct timeval)GETKEY_MAX_WAIT) < 0)
	{
		DEBUG("NEXT CHAR: TIMEOUT%n");
		return (EOF);
	}
	if (FD_ISSET(fd, &fdr))
	{
		if (read(fd, &c, 1) <= 0)
		{
			DEBUG("NEXT CHAR: FAIL%n");
			return (EOF);
		}
		DEBUG("NEXT CHAR: %d '%c'%n", c, c);
		return (c);
	}
	DEBUG("NEXT CHAR: 0%n");
	return ('\0');
}

static t_key	parse_utf8(char c)
{
	return (KEY(c, 0));
	// TODO utf-8
}

/*
** '\033' start (n1 (';' n2)?)? end
** start (char): '[' | 'O'
** n1 (digit, def: 1)
** n2 (digit, def: 0): 2 (shift) | 3|9 (alt) | 5 (ctrl)
** end (char)
** if end == '~': n1 is used
*/
static t_key	parse_seq_end(uint32_t mods, char end)
{
	int				i;
	t_key			key;

	key = KEY('\0', mods);
	i = -1;
	while (++i < ARRAY_LEN(g_seq_ends))
	{
		if (g_seq_ends[i].end == end)
		{
			key.c = g_seq_ends[i].c;
			key.mods |= g_seq_ends[i].mods;
			return (key);
		}
	}
	DEBUG("PARSE SEQ END: Invalid end: (%d) %c (%.1r)%n", mods, end, &end);
	return (key);
}

static t_key	parse_seq(int fd, uint32_t mods)
{
	int				n1;
	int				n2;
	char			c;

	n1 = 1;
	c = next_char(fd);
	if (IS(c, IS_DIGIT))
	{
		n1 = c - '0';
		c = next_char(fd);
	}
	if (c == ';')
	{
		n2 = 0;
		c = next_char(fd);
		while (IS(c, IS_DIGIT))
		{
			n2 = n2 * 10 + c - '0';
			c = next_char(fd);
		}
		mods |= n2 - 1;
	}
	return (parse_seq_end(mods, (c == '~') ? n1 : c));
}

static t_key	get_esc_seq(int fd)
{
	char			c;
	uint32_t		mods;

	mods = 0;
	while ((c = next_char(fd)) == '\033')
		mods |= KEY_MOD_ALT;
	if (c == '[' || c == 'O')
		return (parse_seq(fd, mods));
	else if (c == '\0')
		c = '\033';
	return (KEY(c, 0));
}

t_key			ft_getkey(int fd)
{
	char			c;

	if (read(fd, &c, 1) <= 0)
		c = EOF;
	else
	{
		DEBUG("GETCHAR: %d: %d '%c'%n", fd, c, c);
		if (c < 0 || c > 127)
			return (parse_utf8(c));
		else if (c == '\033')
			return (get_esc_seq(fd));
		else if (c >= 1 && c <= 26)
			return (KEY('a' + c - 1, KEY_MOD_CTRL));
		else if (IS(c, IS_UPPER))
			return (KEY(c, KEY_MOD_SHIFT));
	}
	return (KEY(c, 0));
}
