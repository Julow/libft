/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:01:45 by jaguillo          #+#    #+#             */
/*   Updated: 2016/07/06 21:56:09 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "ft/ft_vector.h"
# include "ft/libft.h"
# include "ft/regex.h"
# include "ft/tokenizer.h"

typedef struct s_parser			t_parser;
typedef struct s_parser_token	t_parser_token;
typedef struct s_parser_match	t_parser_match;

typedef struct s_parse_data		t_parse_data;
typedef struct s_parse_frame	t_parse_frame;

/*
** ========================================================================== **
** Parsing
*/

struct			s_parse_frame
{
	t_parser const	*parser;
	void			*data;
	t_parse_frame	*prev;
};

/*
** Parse data
** -
** 'env'		User data
** 't'			Tokenizer
** 'frame'		The current frame
** 'flags'		Flags:
** 			PARSE_F_FIRST	Set when parse_token return it's first token
** 			PARSE_F_EOF		Set on EOF
** 			PARSE_F_ERROR	Set after a call to parse_error
** 'token'		The current token's string
** 'token_data'	The current token's data
*/

struct			s_parse_data
{
	void			*env;
	t_tokenizer		t;
	t_parse_frame	*frame;
	uint32_t		flags;
	t_sub			token;
	void const		*token_data;
};

# define PARSE_DATA(ENV, IN)	((t_parse_data){(ENV),.t=TOKENIZER(IN,NULL)})
# define D_PARSE_DATA(P)		(ft_tokenizer_reset(&((P).t), true))

# define PARSE_EOF(P)		((P)->flags & PARSE_F_EOF)
# define PARSE_ERROR(P)		((P)->flags & PARSE_F_ERROR)

# define PARSE_F_EOF		(1 << 2)
# define PARSE_F_ERROR		(1 << 3)

# define PARSE_F_FIRST		(1 << 0)
# define _PARSE_F_FIRST		(1 << 1)

/*
** Iterate over tokens
** 'p->eof' is set to true on EOF
** 'p->token' represent the token string
** 'p->token_data' represent the token data
** Return false when current frame should stop
** On returning false: 'p->token' and 'p->token_data'
**  are set to the end token's datas
*/
bool			ft_parse_token(t_parse_data *p);

/*
** Create a new frame and execute 'parser'
** Call 'f' function store in each parsers
** 'p->token' and 'p->token_data' are set to the begin token's datas
** Parsing stop when 'f' return false
*/
bool			ft_parse(t_parse_data *p, t_parser const *parser);

/*
** Set error flag
** Return false
** 'p->token' are set to 'err'
*/
bool			ft_parse_error(t_parse_data *p, t_sub err);

/*
** ========================================================================== **
** Parser
** -
** TODO: .tail		call next parser without recursion
** TODO: .nofail	error on unmatched token
*/

struct			s_parser_token
{
	void const		*data;
	t_parser		*parser;
	bool			end;
};

struct			s_parser_match
{
	t_regex			regex;
	t_parser_token	token;
};

struct			s_parser
{
	void			*data;
	bool			(*f)(t_parse_data *);
	t_token_map		token_map;
	t_vector		match;
	bool			resolved;
};

#endif
