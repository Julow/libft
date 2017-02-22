/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 14:19:11 by juloo             #+#    #+#             */
/*   Updated: 2017/02/22 18:33:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "out_internal.h"

static char const	g_printable_short[128] = {
	['\0'] = '0',
	['\a'] = 'a',
	['\b'] = 'b',
	['\f'] = 'f',
	['\n'] = 'n',
	['\r'] = 'r',
	['\t'] = 't',
	['\v'] = 'v',
};

#define IS_PRINTABLE	(IS_PRINT | IS_NEWLINE)

static void		putsub_printable(t_out *out, t_sub sub)
{
	char			buff[sub.length * 4 + 1];
	uint32_t		i;
	uint32_t		buff_i;

	i = 0;
	buff_i = 0;
	while (i < sub.length)
	{
		if (out->flags & OUT_PRINTABLE_SHORT && (uint8_t)sub.str[i] < 128
				&& g_printable_short[(uint8_t)sub.str[i]] != '\0')
		{
			buff[buff_i++] = '\\';
			buff[buff_i++] = g_printable_short[(uint8_t)sub.str[i]];
		}
		else if (out->flags & OUT_PRINTABLE
			&& !IS(sub.str[i], IS_PRINTABLE))
		{
			buff[buff_i++] = '\\';
			buff[buff_i++] = 'x';
			buff[buff_i++] = BASE_16[(uint8_t)sub.str[i] / 16];
			buff[buff_i++] = BASE_16[(uint8_t)sub.str[i] % 16];
		}
		else
			buff[buff_i++] = sub.str[i];
		i++;
	}
	ft_putpad_left(out, buff_i);
	ft_write(out, buff, buff_i);
	ft_putpad_right(out, buff_i);
}

void			ft_putsub(t_out *out, t_sub sub)
{
	if (out->flags & (OUT_PRINTABLE | OUT_PRINTABLE_SHORT))
		return (putsub_printable(out, sub));
	ft_putpad_left(out, sub.length);
	ft_write(out, sub.str, sub.length);
	ft_putpad_right(out, sub.length);
}

void			ft_putstr(t_out *out, char const *data, int32_t len)
{
	if (len < 0)
		len = ft_strlen(data) + len + 1;
	ft_putsub(out, SUB(data, len));
}
