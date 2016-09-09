/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenmap_builder.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 15:42:34 by juloo             #+#    #+#             */
/*   Updated: 2016/09/09 12:48:15 by juloo            ###   ########.fr       */
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
** -
** Pattern:
** '\0+set\0'
** 'set' can be a collection of character or char-range (a-z)
** '+' is optionnal and mean repeated one or more
*/

struct			s_tokenmap_builder_t
{
	t_vec2u			str;
	void const		*data;
};

struct			s_tokenmap_builder
{
	t_dstr			str_buff;
	t_vector		tokens;
	void const		*def;
};

# define TOKENMAP_BUILDER()	((t_tokenmap_builder){DSTR0(), VECTOR(t_tokenmap_builder_t), NULL})

/*
** Add a token
** If 'pattern' is empty, set the default token
** Return true on success
** Return false on dupplicate (and do not add it)
*/
bool			ft_tokenmap_builder_add(t_tokenmap_builder *b,
					t_sub pattern, void const *data);

/*
** Create a tokenmap
** The tokenmap_builder object is destroyed
** -
** In case of error, assert are print but do not fail
*/
t_tokenmap		*ft_tokenmap_builder_done(t_tokenmap_builder *b);

#endif
