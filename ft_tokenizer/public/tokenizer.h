/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:19:33 by jaguillo          #+#    #+#             */
/*   Updated: 2016/08/03 18:17:59 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "ft/ft_bst.h"
# include "ft/ft_dstr.h"
# include "ft/ft_in.h"
# include "ft/libft.h"

typedef struct s_token_map		t_token_map;
typedef struct s_token_map_t	t_token_map_t;
typedef struct s_tokenizer		t_tokenizer;

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
	t_token_map const	*token_map;
	t_dstr				buff;
	uint32_t			end;
	t_sub				token;
	void const			*token_data;
};

/*
** TOKENIZER(IN, TOKEN_MAP)		Init a tokenizer
*/
# define TOKENIZER(IN,MAP)	((t_tokenizer){(IN),(MAP),DSTR0(),0,SUB0(),NULL})

/*
** Read from 'in' and found tokens of 'map'
** 't' have to be initialized with TOKENIZER()
** 't->token' is a sub string of the token
** 't->token_data' is the token's data (or NULL if it's an unmatched token)
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

struct			s_token_map_t
{
	t_sub			str;
};

struct			s_token_map
{
	t_bst			tokens;
	t_bits			token_starts[BITARRAY((uint8_t)(-1))];
};

/*
** Init a token map
*/
# define TOKEN_MAP()   ((t_token_map){BST(t_token_map_t, &token_map_cmp), {}})

/*
** Add a token
** 'str' is copied
** Return a ptr to an alloc of 'size' byte
** Return NULL if the token is already in the token map
*/
void			*ft_tokenmap_add(t_token_map *map, t_sub str, uint32_t size);

/*
** Destroy a token map
** The 'map' ptr is not freed
** If 'f' is not NULL, it is called for each token data
*/
void			ft_tokenmap_destroy(t_token_map *map, void (*f)(void*));

/*
** -
*/

int				token_map_cmp(t_token_map_t const *a, t_sub const *b);

#endif
