/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 18:32:55 by juloo             #+#    #+#             */
/*   Updated: 2016/09/08 23:53:04 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT__LEXER_H
# define FT__LEXER_H

# include "ft/ft_vector.h"
# include "ft/libft.h"
# include "ft/tokenizer.h"

typedef t_tokenmap const			*t_lexer_frame;

typedef struct s_lexer_def			t_lexer_def;
typedef struct s_lexer_state_def	t_lexer_state_def;
typedef struct s_lexer_token_def	t_lexer_token_def;

/*
** ========================================================================== **
** Lexer
*/

/*
** Begin a new frame
** Previous frame data is saved in 'save'
*/
void			ft_lexer_push(t_tokenizer *t, t_lexer_frame *save,
					t_lexer_def *def);

/*
** End of the current frame, restore 'prev'
*/
void			ft_lexer_pop(t_tokenizer *t, t_lexer_frame const *prev);

/*
** ========================================================================== **
** Lexer def
*/

/*
** Lexer def object
** tokenmap			=> Tokenmap object (initially NULL, build when needed)
** libs				=> Libs of reusable states (vector of t_lexer_def const*)
** def				=> Defined states (vector of t_lexer_state_def)
** main_state		=> Name of the main state
*/
struct			s_lexer_def
{
	t_tokenmap		*tokenmap;
	t_vector		libs;
	t_vector		def;
	t_sub			main_state;
};

/*
** Lexer state def
** name				=> State name
** parents			=> Name of parent states (vector of char const*)
** tokens			=> Defined tokens (vector of t_lexer_token_def)
*/
struct			s_lexer_state_def
{
	t_sub			name;
	t_vector		parents;
	t_vector		tokens;
};

/*
** Lexer token def
** str				=> Token string (to be passed to ft_tokenmap_builder_add)
** data				=> Custom data ptr
*/
struct			s_lexer_token_def
{
	t_sub			str;
	void const		*data;
};

/*
** Init a t_lexer_def
** L			=> Libs (list of t_lexer_def const*)
** M			=> Main state (string)
** ...			=> List of t_lexer_state_def
*/
# define LEXER_DEF(L, M, ...)	((t_lexer_def){NULL, VECTORC((t_lexer_def const*[])LST L), VECTOR(t_lexer_state_def, ##__VA_ARGS__), SUBC(M)})

/*
** Init a t_lexer_state_def
** N			=> State name (string)
** P			=> Parent states (list of string)
** ...			=> Tokens (list of t_lexer_token_def)
*/
# define LEXER_STATE(N,P,...)	((t_lexer_state_def){SUBC(N),VECTORC(((char const*[])LST P)),VECTORC(((t_lexer_token_def[]){__VA_ARGS__}))})

/*
** Init a t_lexer_token_def
** S			=> Token string
** D			=> Data
*/
# define LEXER_T(S,D)		((t_lexer_token_def){SUBC(S), .data=(D)})

// TODO: move
# define LST(...)			{ __VA_ARGS__ }

#endif
