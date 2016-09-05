/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:19:33 by jaguillo          #+#    #+#             */
/*   Updated: 2016/09/05 17:31:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "ft/ft_dstr.h"
# include "ft/ft_in.h"
# include "ft/libft.h"

typedef struct s_tokenmap_idx		t_tokenmap_idx;
typedef struct s_tokenmap_match		t_tokenmap_match;
typedef struct s_tokenmap_t			t_tokenmap_t;
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
	bool				eof;
};

/*
** TOKENIZER(IN, TOKEN_MAP)		Init a tokenizer
*/
# define TOKENIZER(IN,MAP)	((t_tokenizer){(IN),(MAP),DSTR0(),0,SUB0(),NULL,false})

/*
** Read from 'in' and found tokens of 'map'
** 't' have to be initialized with TOKENIZER()
** 't->token' is a sub string of the token
** 't->token_data' is the token's data
** 		or default token data if it's an unmatched token
** 		(if there is no default token data, return false)
** It's safe to set 't->in' and 't->token_map' between 2 calls
** Return false on EOF or on unmatched token with no default token
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

struct			s_tokenmap_idx
{
	uint16_t		idx;
	uint16_t		len;
};

struct			s_tokenmap_match
{
	enum {
		TOKENMAP_MATCH_STR,
		TOKENMAP_MATCH_SET,
		TOKENMAP_MATCH_SET_REPEAT,
	}				type;
	union {
		struct {
			char			c[28];
			uint32_t		length;
		}				str;
		t_bits			set[BITARRAY(256)];
	};
};

struct			s_tokenmap_t
{
	t_tokenmap_match	*match;
	uint32_t			match_count;
	void const			*data;
};

struct			s_tokenmap
{
	t_tokenmap_idx		idx[256];
	t_tokenmap_t const	**t;
	void const			*def;
};

#endif
