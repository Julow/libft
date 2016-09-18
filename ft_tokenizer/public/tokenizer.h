/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:19:33 by jaguillo          #+#    #+#             */
/*   Updated: 2016/09/18 11:14:54 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "ft/buff_in.h"
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
** buff			=> source stream
** token_map	=> tokens
** token_str	=> current token string
** token		=> current token's data
** eof			=> set when EOF is hit
*/
struct			s_tokenizer
{
	t_buff_in			buff;
	t_tokenmap const	*token_map;
	t_sub				token_str;
	void const			*token;
	bool				eof;
};

/*
** TOKENIZER(BUFF, TOKEN_MAP)		Init a tokenizer
*/
# define TOKENIZER(IN,M)	((t_tokenizer){BUFF_IN(IN),(M),SUB0(),NULL,false})

/*
** Read from 'buff' and recognize tokens of 'map'
** 't' have to be initialized with TOKENIZER()
** 't->token' is a sub string of the token
** 't->token_data' is the token's data
** 		or default token data if it's an unmatched token
** 		(if there is no default token data, return false)
** It's safe to set 't->token_map' between 2 calls
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
** Reset a tokenizer
** Does not unset/destroy 'in' and 'token_map'
** The tokenizer is reusable after a reset
*/
void			ft_tokenizer_reset(t_tokenizer *t);

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
