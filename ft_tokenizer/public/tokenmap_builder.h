/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenmap_builder.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 15:42:34 by juloo             #+#    #+#             */
/*   Updated: 2016/08/27 19:11:15 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENMAP_BUILDER_H
# define TOKENMAP_BUILDER_H

# include "ft/ft_dstr.h"
# include "ft/ft_vector.h"
# include "ft/tokenizer.h"

typedef struct s_tokenmap_builder		t_tokenmap_builder;
typedef struct s_tokenmap_builder_t		t_tokenmap_builder_t;

/*
** ========================================================================== **
** Tokenmap builder
*/

struct			s_tokenmap_builder_t
{
	t_vec2u			str;
	t_vec2u			data;
};

struct			s_tokenmap_builder
{
	t_dstr			str_buff;
	t_dstr			data_buff;
	t_vector		tokens;
};

# define TOKENMAP_BUILDER()	((t_tokenmap_builder){DSTR0(), DSTR0(), VECTOR(t_tokenmap_builder_t)})

/*
** Add a token
** 'str' is copied
** If 'str' is empty, set a default token (for unmatched tokens)
** Return a ptr to an alloc of 'size' byte
** Return NULL if the token is already in the token map
*/
void			*ft_tokenmap_builder_add(t_tokenmap_builder *b,
					t_sub str, uint32_t data_size);

/*
** Create a tokenmap
** The tokenmap_builder object is destroyed
*/
t_tokenmap		*ft_tokenmap_builder_done(t_tokenmap_builder *b);

#endif
