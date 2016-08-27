/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 18:32:55 by juloo             #+#    #+#             */
/*   Updated: 2016/08/27 19:14:38 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT__LEXER_H
# define FT__LEXER_H

# include "ft/ft_vector.h"
# include "ft/libft.h"
# include "ft/tokenizer.h"

typedef struct s_lexer				t_lexer;
typedef struct s_lexer_frame		t_lexer_frame;

typedef struct s_lexer_state		t_lexer_state;
typedef struct s_lexer_token		t_lexer_token;

typedef t_vector					t_lexer_def;
typedef struct s_lexer_state_def	t_lexer_state_def;
typedef struct s_lexer_token_def	t_lexer_token_def;

/*
** ========================================================================== **
** Lexer
*/

/*
** Lexer object
** t				=> tokenizer object
** state			=> current state
** token			=> current token data or NULL for unmatched tokens
** eof				=> Set when end-of-file is hit
** should_push		=> Token with push attribute
** should_pop		=> Token with pop attribute
*/
struct			s_lexer
{
	t_tokenizer			t;
	t_lexer_state const	*state;
	void const			*token;
	bool				eof:1;
	bool				should_push:1;
	bool				should_pop:1;
};

/*
** Init lexer
** IN				=> In stream
** S+				=> Initial state
*/
# define LEXER(IN, S)	((t_lexer){TOKENIZER(IN,(S)->token_map),.state=S})

/*
** Begin a new frame after a token with the 'push' attribute
** Previous frame data is saved in 'save'
** unset 'should_push'
** Must not be called if 'should_push' is not set
*/
void			ft_lexer_push(t_lexer *l, t_lexer_state const **save);

/*
** Restore the previously pushed frame
** unset 'should_pop'
** If 'prev' is NULL, terminate lexing
*/
void			ft_lexer_pop(t_lexer *l, t_lexer_state const *prev);

/*
** Go to the next token
** Return true on success, false on EOF or error
** l->token is updated
** Should not be called if 'should_push' or 'should_pop' is set
*/
bool			ft_lexer_next(t_lexer *l);

/*
** Look ahead for the next token
** 's' and 'data' are set to the next token's string and data
** Return true on success, false on EOF or error
** Should not be called if 'should_push' or 'should_pop' is set
*/
bool			ft_lexer_ahead(t_lexer *l, t_sub *s, void const **data);

/*
** Destroy a lexer
*/
void			ft_lexer_destroy(t_lexer *l);

/*
** ========================================================================== **
** Lexer state
*/

struct			s_lexer_state
{
	t_sub			name;
	t_tokenmap		*token_map;
};

struct			s_lexer_token
{
	void const		*data;
	t_lexer_state	*push;
	bool			pop;
};

void			ft_lexer_destroy_state(t_lexer_state *state);

/*
** ========================================================================== **
** Lexer def
*/

struct			s_lexer_state_def
{
	t_sub			name;
	t_vector		parents;
	t_vector		tokens;
};

struct			s_lexer_token_def
{
	t_sub			str;
	void const		*data;
	char const		*push;
	bool			pop;
};

/*
** Init a t_lexer_def
** ...			=> List of t_lexer_state_def
*/
# define LEXER_DEF(...)		((t_lexer_def)VECTOR(t_lexer_state_def, ##__VA_ARGS__))

/*
** Init a t_lexer_state_def
** N			=> State name (string)
** P			=> Parent states (array of string)
** ...			=> Tokens (list of t_lexer_token_def)
*/
# define LEXER_STATE(N,P,...)	((t_lexer_state_def){SUBC(N),VECTORC(((char const*[])LST P)),VECTORC(((t_lexer_token_def[]){__VA_ARGS__}))})

/*
** Init a t_lexer_token_def
** S			=> Token string
** D			=> Data
** ...			=> Optionnal params:
** 					.push=		Name of the state to push (string)
** 					.pop=		Pop flag (bool)
*/
# define LEXER_T(S,D,...)	((t_lexer_token_def){SUBC(S), .data=(D), __VA_ARGS__})

/*
** Build a t_lexer_state
** Return NULL on error
*/
t_lexer_state	*ft_lexer_build(t_lexer_def const *def, t_sub main_state);

// TODO: move
# define LST(...)			{ __VA_ARGS__ }

#endif
