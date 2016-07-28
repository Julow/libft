/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:01:45 by jaguillo          #+#    #+#             */
/*   Updated: 2016/07/28 18:18:52 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT__PARSER_H
# define FT__PARSER_H

# include "ft/ft_vector.h"
# include "ft/libft.h"
# include "ft/tokenizer.h"

typedef struct s_parser			t_parser;
typedef struct s_parser_token	t_parser_token;

typedef struct s_parse_data		t_parse_data;

/*
** ========================================================================== **
** Parsing
*/

/*
** Parse data
** -
** 'env'		User data
** 't'			Tokenizer
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
** 'param' is passed to the new frame (if any)
** Return false when current frame should stop
** 'p->token' and 'p->token_data' are set to the current token
** On EOF, return false and set the EOF flag
*/
bool			ft_parse_token(t_parse_data *p, void *param);

/*
** Execute 'parser'
** 'p->token' and 'p->token_data' are set to the begin token
*/
bool			ft_parse(t_parse_data *p, t_parser const *parser, void *param);

/*
** Set error flag
** Return false
*/
bool			ft_parse_error(t_parse_data *p);

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

/*
** data			=> parser's custom data
** f			=> frame function
** token_map	=> ft::tokenizer's token_map
** resolved		=> TODO: remove this shit
*/
struct			s_parser
{
	void const		*data;
	bool			(*f)(t_parse_data*, void const *data, void *param);
	t_token_map		token_map;
	bool			resolved;
};

#endif
