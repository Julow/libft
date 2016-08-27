/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenmap_builder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 15:55:22 by juloo             #+#    #+#             */
/*   Updated: 2016/08/28 00:19:16 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tokenmap_builder.h"
#include "p_tokenmap_builder.h"

static bool		dupplicated_token(t_tokenmap_builder *b, t_sub str)
{
	t_tokenmap_builder_t const	*t;

	t = VECTOR_IT(b->tokens);
	while (VECTOR_NEXT(b->tokens, t))
		if (SUB_EQU(SUB(b->str_buff.str + t->str.x, t->str.y), str))
			return (true);
	return (false);
}

void			*ft_tokenmap_builder_add(t_tokenmap_builder *b,
					t_sub str, uint32_t data_size)
{
	t_tokenmap_builder_t	t;
	void					*data;

	if (dupplicated_token(b, str))
		return (NULL);
	t.str = VEC2U(b->str_buff.length, str.length);
	ft_dstradd(&b->str_buff, str);
	b->data_buff.length = ALIGN_UP(b->data_buff.length, 8);
	t.data = VEC2U(b->data_buff.length, data_size);
	ft_dstrextend(&b->data_buff, data_size);
	data = b->data_buff.str + b->data_buff.length;
	b->data_buff.length += data_size;
	ft_vpush(&b->tokens, &t, 1);
	return (data);
}

static t_tokenmap_state	*tokenmap_build_state(t_tokenmap_b_t const *t,
							uint32_t count, uint32_t offset)
{
	char					chars[count];
	t_tokenmap_state		*states[count];
	uint32_t				state_count;
	uint32_t				i;
	uint32_t				c;
	void const				*data;
	t_tokenmap_state		*state;

	data = NULL;
	state_count = 0;
	i = 0;
	while (i < count)
	{
		if (t[i].str.length <= offset)
		{
			ASSERT(t[i].str.length == offset);
			ASSERT(data == NULL, "dupplicated token");
			data = t[i].data;
			i++;
			continue ;
		}

		c = i + 1;
		while (c < count && t[c].str.length > offset
			&& t[c].str.str[offset] == t[i].str.str[offset])
			c++;

		states[state_count] = tokenmap_build_state(t + i, c - i, offset + 1);
		chars[state_count] = t[i].str.str[offset];
		state_count++;

		i = c;
	}

	state = MALLOC(sizeof(t_tokenmap_state)
			+ ALIGN_UP(state_count, 8)
			+ S(t_tokenmap_state, state_count));
	*state = (t_tokenmap_state){
		state_count,
		data,
		ENDOF(state),
		ENDOF(state) + ALIGN_UP(state_count, 8)
	};
	ft_memcpy(ENDOF(state), chars, state_count);
	ft_memcpy(V(state->states), states, S(t_tokenmap_state*, state_count));
	return (state);
}

static int		tokenmap_b_t_cmp(t_tokenmap_b_t const *data,
					uint32_t a, uint32_t b)
{
	uint32_t const	len = MIN(data[a].str.length, data[b].str.length);
	uint32_t		i;

	i = 0;
	while (i < len)
	{
		if (data[a].str.str[i] != data[b].str.str[i])
			return (data[a].str.str[i] - data[b].str.str[i]);
		i++;
	}
	return (data[a].str.length - data[b].str.length);
}

static void		tokenmap_b_t_swap(t_tokenmap_b_t *data,
					uint32_t a, uint32_t b)
{
	t_tokenmap_b_t const	tmp = data[a];

	data[a] = data[b];
	data[b] = tmp;
}

t_tokenmap		*ft_tokenmap_builder_done(t_tokenmap_builder *b)
{
	t_tokenmap_b_t				t[b->tokens.length];
	t_tokenmap					*tokenmap;
	t_tokenmap_builder_t const	*tmp;
	uint32_t					i;

	tokenmap = MALLOC(sizeof(t_tokenmap) + b->data_buff.length);
	ft_bzero(tokenmap, sizeof(t_tokenmap));
	i = 0;
	while (i < b->tokens.length)
	{
		tmp = VECTOR_GET(b->tokens, i);
		t[i] = (t_tokenmap_b_t){
			SUB(b->str_buff.str + tmp->str.x, tmp->str.y),
			ENDOF(tokenmap) + tmp->data.x
		};
		if (tmp->str.y > 0)
			BITARRAY_SET(tokenmap->first, b->str_buff.str[tmp->str.x]);
		i++;
	}
	ft_sort(t, b->tokens.length,
		V(&tokenmap_b_t_cmp), V(&tokenmap_b_t_swap));
	tokenmap->s = tokenmap_build_state(t, b->tokens.length, 0);
	ft_memcpy(ENDOF(tokenmap), b->data_buff.str, b->data_buff.length);
	ft_dstrclear(&b->str_buff);
	ft_dstrclear(&b->data_buff);
	ft_vclear(&b->tokens);
	return (tokenmap);
}
