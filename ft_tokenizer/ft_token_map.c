/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:06:57 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/19 15:04:41 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tokenizer.h"

int			token_map_cmp(t_token_def const *a, t_sub const *b)
{
	if (a->sub.length == 0 || b->length == 0)
		return (a->sub.length - b->length);
	return (a->sub.str[0] - b->str[0]);
}

void		ft_token_map(t_token_map *map, t_token_def const *token)
{
	t_token_def		*t;

	ASSERT(token->sub.length > 0);
	BITARRAY_SET(map->token_starts, token->sub.str[0]);
	t = ft_bst_put(&map->tokens, &token->sub, token->sub.length);
	*t = (t_token_def){
		SUB(ENDOF(t), token->sub.length),
		token->data
	};
	ft_memcpy(ENDOF(t), token->sub.str, token->sub.length);
}
