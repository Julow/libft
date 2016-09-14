/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 17:36:21 by jaguillo          #+#    #+#             */
/*   Updated: 2016/09/14 19:32:53 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tokenizer.h"
#include <stdlib.h>

static void		buff_in_shift(t_buff_in *in, char *dst)
{
	ft_memcpy(dst, in->buff + in->i, in->length - in->i);
	in->length -= in->i;
	in->i = 0;
}

static void		buff_in_realloc(t_buff_in *in)
{
	uint32_t		tmp;
	char			*dst;

	tmp = (in->length - in->i) * 2 + in->in->buff_len - in->in->buff_i;
	if (tmp < BUFF_IN_MIN_BUFF)
		tmp = BUFF_IN_MIN_BUFF;
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
	tmp = in->length - in->i + in->in->buff_len - in->in->buff_i;
	if (tmp > in->buff_capacity)
		buff_in_realloc(in);
	else
		buff_in_shift(in, in->buff);
	tmp = in->in->buff_len - in->in->buff_i;
	ft_memcpy(in->buff + in->length, in->in->buff + in->in->buff_i, tmp);
	in->length += tmp;
	in->in->buff_i = in->in->buff_len;
	return (true);
}

void			ft_buff_in_clear(t_buff_in *in)
{
	if (in->buff_capacity != 0)
		free(in->buff);
	*in = BUFF_IN(NULL);
}
