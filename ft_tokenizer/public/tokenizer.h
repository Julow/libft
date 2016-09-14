/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:19:33 by jaguillo          #+#    #+#             */
/*   Updated: 2016/09/14 19:52:32 by jaguillo         ###   ########.fr       */
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

typedef struct s_buff_in			t_buff_in;

/*
** ========================================================================== **
** Buffered in
** -
** TODO: export to it's own module
*/

/*
** in				=> source stream
** buff				=> buffer
** buff_end			=> end offset in the buffer
** buff_capacity	=> allocated buff size
*/
struct			s_buff_in
{
	t_in			*in;
	char			*buff;
	uint32_t		i;
	uint32_t		length;
	uint32_t		buff_capacity;
};

# define BUFF_IN(IN)		((t_buff_in){(IN), NULL, 0, 0, 0})

# define BUFF_IN_MIN_BUFF	32

/*
** Check if 'B.i + I' is a valid index
** Read if needed
*/
# define BUFF_IN_CHECK(B,I)	(((B).i + (I)) < (B).length || ft_buff_in_read(&(B)))

/*
** Return char at 'B.i + I'
*/
# define BUFF_IN_GETC(B,I)	((B).buff[(B).i + (I)])

/*
** Read a full buffer from the source stream
** Discard characters not in the range ['i', 'length')
** Return true on success, false on EOF
*/
bool			ft_buff_in_read(t_buff_in *in);

/*
** Clear/free
** The object is reusable after a clear
*/
void			ft_buff_in_clear(t_buff_in *in);

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
** -
*/
void			ft_tokenizer_inject(t_tokenizer *t, t_sub s);

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
