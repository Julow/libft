/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 17:36:21 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/12 12:18:52 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/buff_in.h"
#include <stdlib.h>

static void		buff_in_shift(t_buff_in *in, char *dst)
{
	memmove(dst, in->buff + in->i, in->length - in->i);
	in->length -= in->i;
	in->i = 0;
}

static void		buff_in_realloc(t_buff_in *in, uint32_t need)
{
	uint32_t		tmp;
	char			*dst;

	if ((need + in->length) <= in->buff_capacity)
		return ;
	need += in->length - in->i;
	if (need <= in->buff_capacity)
	{
		buff_in_shift(in, in->buff);
		return ;
	}
	tmp = MAX(BUFF_IN_MIN_BUFF, in->buff_capacity);
	while (tmp < need)
		tmp *= 2;
	dst = MALLOC(tmp);
	buff_in_shift(in, dst);
	if (in->buff_capacity > 0)
		free(in->buff);
	in->buff = dst;
	in->buff_capacity = tmp;
}

bool			ft_buff_in_read(t_buff_in *in)
{
	uint32_t		tmp;

	if (!ft_in_refresh(in->in))
		return (false);
	ASSERT(in->in->buff_i < in->in->buff_len);
	tmp = in->in->buff_len - in->in->buff_i;
	buff_in_realloc(in, tmp);
	memcpy(in->buff + in->length, in->in->buff + in->in->buff_i, tmp);
	in->length += tmp;
	in->in->buff_i = in->in->buff_len;
	return (true);
}

void			ft_buff_in_inject(t_buff_in *in, t_sub str)
{
	char			*dst;

	buff_in_realloc(in, str.length);
	dst = in->buff + in->i;
	memmove(dst + str.length, dst, in->length - in->i);
	memcpy(dst, str.str, str.length);
	in->length += str.length;
}

void			ft_buff_in_clear(t_buff_in *in)
{
	if (in->buff_capacity != 0)
		free(in->buff);
	*in = BUFF_IN(NULL);
}
