/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:19:33 by jaguillo          #+#    #+#             */
/*   Updated: 2016/08/28 23:42:11 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "ft/ft_dstr.h"
# include "ft/ft_in.h"
# include "ft/libft.h"

typedef struct s_tokenmap_state		t_tokenmap_state;
typedef struct s_tokenmap			t_tokenmap;
typedef struct s_tokenizer			t_tokenizer;

/*
** ========================================================================== **
** Tokenizer
*/

/*
** Tokenizer object
** in			=> source stream
** token_map	=> tokens
** buff			=> (internal) buffer
** end			=> (internal)
** token		=> current token string
** token_data	=> current token's data
*/
struct			s_tokenizer
{
	t_in				*in;
	t_tokenmap const	*token_map;
	t_dstr				buff;
	uint32_t			end;
	t_sub				token_str;
	void const			*token;
};

/*
** TOKENIZER(IN, TOKEN_MAP)		Init a tokenizer
*/
# define TOKENIZER(IN,MAP)	((t_tokenizer){(IN),(MAP),DSTR0(),0,SUB0(),NULL})

/*
** Read from 'in' and found tokens of 'map'
** 't' have to be initialized with TOKENIZER()
** 't->token' is a sub string of the token
** 't->token_data' is the token's data
** 		(or default token data if it's an unmatched token)
** It's safe to set 't->in' and 't->token_map' between 2 calls
*/
bool			ft_tokenize(t_tokenizer *t);

/*
** Look for the next token
** 't->token' is still the previous token but may have been modified
** 's' and 'data' are set to the next token's string and data
** Return false on EOF
*/
bool			ft_tokenize_ahead(t_tokenizer *t, t_sub *s, void const **data);

/*
** -
*/
void			ft_tokenizer_inject(t_tokenizer *t, t_sub s);

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

struct			s_tokenmap_state
{
	uint32_t				count;
	void const				*data;
	char const				*c;
	t_tokenmap_state *const	*states;
};

struct			s_tokenmap
{
	t_bits				first[BITARRAY((uint8_t)(-1))];
	t_tokenmap_state	*s;
};

#endif
