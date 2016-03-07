/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getkey.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:58:48 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/07 14:47:33 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/getkey.h"
#include "getkey_internal.h"

#include <unistd.h>

/*
** TODO utf-8
*/

static t_key	parse_utf8(char c)
{
	return (KEY(c, 0));
}

t_key			ft_getkey(int fd)
{
	char			c;

	if (read(fd, &c, 1) <= 0)
		c = EOF;
	else if (c < 0 || c > 127)
		return (parse_utf8(c));
	else if (c == '\033')
		return (get_esc_seq(fd));
	else if (c >= 1 && c <= 26)
		return (KEY('a' + c - 1, MOD_CTRL));
	else if (IS(c, IS_UPPER))
		return (KEY(c, MOD_SHIFT));
	return (KEY(c, 0));
}
