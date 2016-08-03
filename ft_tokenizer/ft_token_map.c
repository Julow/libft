/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:06:57 by jaguillo          #+#    #+#             */
/*   Updated: 2016/08/03 18:23:28 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tokenizer.h"

int			token_map_cmp(t_token_map_t const *a, t_sub const *b)
{
	if (a->str.length == 0 || b->length == 0)
		return (a->str.length - b->length);
	return (a->str.str[0] - b->str[0]);
}

static bool	unique_token(void *env, t_token_map_t const *def, t_sub const *match)
{
	return (!SUB_EQU(def->str, *match));
	(void)env;
}

void		*ft_tokenmap_add(t_token_map *map, t_sub str, uint32_t data_size)
{
	t_token_map_t	*t;
	char			*str_dst;

	ASSERT(str.length > 0);
	if (!ft_bst_getall(&map->tokens, &str, &unique_token, NULL))
	{
		ft_printf("DUP TOKEN %ts%n", str);
		return (NULL);
	}
	ft_printf("    TOKEN %ts%n", str);
	BITARRAY_SET(map->token_starts, str.str[0]);
	t = ft_bst_put(&map->tokens, &str, data_size + str.length);
	str_dst = ENDOF(t) + data_size;
	*t = (t_token_map_t){SUB(str_dst, str.length)};
	ft_memcpy(str_dst, str.str, str.length);
	return (ENDOF(t));
}

static void	tokenmap_destroy_data(t_token_map_t *t, void (*f)(void*))
{
	f(ENDOF(t));
}

void		ft_tokenmap_destroy(t_token_map *map, void (*f)(void*))
{
	if (f != NULL)
		ft_bst_destroy(&map->tokens, &tokenmap_destroy_data, f);
	else
		ft_bst_destroy(&map->tokens, NULL, NULL);
}
