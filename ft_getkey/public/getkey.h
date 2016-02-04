/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getkey.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:52:47 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/04 12:28:03 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETKEY_H
# define GETKEY_H

# include "ft/libft.h"

typedef struct s_key		t_key;

/*
** ========================================================================== **
** Get key
*/

struct		s_key
{
	int			c;
	uint32_t	mods;
};

# define KEY(C,F)			((t_key){(C), (F)})

# define MOD_CTRL			(1 << 2)
# define MOD_ALT			((1 << 1) | (1 << 3))
# define MOD_SHIFT			(1 << 0)

# define GETKEY_SPECIAL		0xF0000

# define KEY_BACKSPACE		0x7F
# define KEY_ESC			0x1B
# define KEY_UP				(GETKEY_SPECIAL + 1)
# define KEY_RIGHT			(GETKEY_SPECIAL + 2)
# define KEY_DOWN			(GETKEY_SPECIAL + 3)
# define KEY_LEFT			(GETKEY_SPECIAL + 4)
# define KEY_DELETE			(GETKEY_SPECIAL + 5)
# define KEY_HOME			(GETKEY_SPECIAL + 7)
# define KEY_END			(GETKEY_SPECIAL + 8)
# define KEY_PAGEUP			(GETKEY_SPECIAL + 9)
# define KEY_PAGEDOWN		(GETKEY_SPECIAL + 10)
# define KEY_F1				(GETKEY_SPECIAL + 11)
# define KEY_F2				(GETKEY_SPECIAL + 12)
# define KEY_F3				(GETKEY_SPECIAL + 13)
# define KEY_F4				(GETKEY_SPECIAL + 14)

# define GETKEY_MAX_WAIT	{0, 100}

/*
** Wait for a key and return it
** -
** If used with ft::term, require TERM_RAW mode
*/
t_key		ft_getkey(int fd);

#endif
