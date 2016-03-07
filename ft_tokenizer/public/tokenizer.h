/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:19:33 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/07 15:12:15 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "ft/ft_bst.h"
# include "ft/ft_dstr.h"
# include "ft/ft_in.h"
# include "ft/libft.h"

typedef struct s_token_def		t_token_def;
typedef struct s_token_map		t_token_map;
typedef struct s_tokenizer		t_tokenizer;

/*
** ========================================================================== **
** Tokenizer
*/

struct			s_tokenizer
{
	t_in				*in;
	t_token_map const	*token_map;
	t_dstr				buff;
	uint32_t			end;
	uint32_t			char_count;
	t_sub				token;
	void				*token_data;
};

/*
** TOKENIZER(IN, TOKEN_MAP)		Init a tokenizer
*/
# define TOKENIZER(IN,MAP)	((t_tokenizer){(IN),(MAP),DSTR0(),0,0,SUB0(),NULL})

/*
** Read from 'in' and found tokens of 'map'
** 't' have to be initialized with TOKENIZER()
** 't->token' is a sub string of the token
** 't->token_data' is the token's data (or NULL if it's an unmatched token)
** It's safe to set 't->in' and 't->token_map' between 2 calls
*/
bool			ft_tokenize(t_tokenizer *t);

/*
** Reset a tokenizer
** If 'destroy' is true, also free the temporary buffer
** Does not unset/destroy 'in' and 'token_map'
** The tokenizer is reusable after a reset
*/
void			ft_tokenizer_reset(t_tokenizer *t, bool destroy);

/*
** ========================================================================== **
** Token map
*/

struct			s_token_def
{
	t_sub			sub;
	void			*data;
};

struct			s_token_map
{
	t_bst			tokens;
	t_bits			token_starts[BITARRAY((uint8_t)(-1))];
};

/*
** Init a token map
*/
# define TOKEN_MAP()   ((t_token_map){BST(t_token_def, &token_map_cmp), {}})

/*
** Add a token to a token_map
** token->sub data is copied
*/
void			ft_token_map(t_token_map *map, t_token_def const *token);

/*
** -
*/

int				token_map_cmp(t_token_def const *a, t_sub const *b);

#endif
