/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_seq.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:39:09 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/11 11:40:05 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getkey_internal.h"

/*
** '\033' start (n1 (';' n2)?)? end
** start (char): '[' | 'O'
** n1 (digit, def: 1)
** n2 (digit, def: 0): 2 (shift) | 3|9 (alt) | 5 (ctrl)
** end (char)
** if end == '~': n1 is used
*/

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
	// DEBUG("PARSE SEQ END: Invalid end: (%d) %c (%.1r)%n", mods, end, &end);
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

t_key			get_esc_seq(int fd)
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
