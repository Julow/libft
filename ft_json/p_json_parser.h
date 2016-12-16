/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_json_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:58:25 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/15 18:36:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_JSON_PARSER_H
# define P_JSON_PARSER_H

# include "ft/json.h"

typedef enum e_json_p_token		t_json_p_token;

/*
** ========================================================================== **
*/

/*
** '{'			-> JSON_P_BRACE_OPEN
** '}'			-> JSON_P_BRACE_CLOSE
** '['			-> JSON_P_SQUARE_OPEN
** ']'			-> JSON_P_SQUARE_CLOSE
** ','			-> JSON_P_COMMA
** ':'			-> JSON_P_COLON
** '"' ( '\\' . | . )* '"'
** 				-> JSON_P_STRING
** [\w\\+\\-\\.\\?#$%<=>@~]+
** 				-> JSON_P_IDENTIFIER
** .			-> JSON_P_ERROR
** [\s\n]+ | '//' .* '\n' | '/' '*' .* '*' '/'
** 				-> ignore
** TODO: single quote string
*/

enum		e_json_p_token
{
	JSON_P_BRACE_OPEN,
	JSON_P_BRACE_CLOSE,
	JSON_P_SQUARE_OPEN,
	JSON_P_SQUARE_CLOSE,
	JSON_P_COMMA,
	JSON_P_COLON,
	JSON_P_STRING,
	JSON_P_IDENTIFIER,
	JSON_P_ERROR,
	JSON_P_EOF,
};

enum		e_json_state
{
	JSON_STATE_DICT,
	JSON_STATE_LIST,
};

t_json_p_token	json_tokenize(t_json_parser *p);

t_json_token	json_parse_value(t_json_parser *p, t_json_p_token t);

t_json_token	json_parse_error(t_json_parser *p, t_sub str);

#endif
