/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_json_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:58:25 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/15 00:04:33 by juloo            ###   ########.fr       */
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
** [\w$~-+<>?.]+
** 				-> JSON_P_IDENTIFIER
** .			-> JSON_P_ERROR
** [\s\n]+ | '//' .* '\n' | '/' '*' .* '*' '/'
** 				-> ignore
*/

/*
** get_value ->
** 	BRACE_OPEN		-> JSON_BEGIN_DICT
** 	SQUARE_OPEN		-> JSON_BEGIN_LIST
** 	STRING			-> JSON_VALUE
** 	IDENTIFIER		-> get_value_t; JSON_VALUE
** 	EOF | ERROR | ?	-> fail
** get_key ->
** 	IDENTIFIER		|
** 	STRING			->
** 			COLON			-> JSON_KEY
** 			EOF | ERROR | ?	-> fail
** 	BRACE_CLOSE		-> END
** 	EOF | ERROR | ?	-> fail
** get_list_item ->
** 	SQUARE_CLOSE	-> END
** 	?				-> get_value
** dict_next ->
** 	COMMA			-> get_key
** 	BRACE_CLOSE		-> END
** 	EOF | ERROR | ?	-> fail
** list_next ->
** 	COMMA			-> get_list_item
** 	SQUARE_CLOSE	-> END
** 	EOF | ERROR | ?	-> fail
** JSON_END -> pop_state; (JSON_VALUE)
** JSON_VALUE ->
** 	STATE_DICT		-> dict_next
** 	STATE_LIST		-> list_next
** 	e				-> fail Syntax error
** JSON_BEGIN_DICT -> push_state DICT; get_key
** JSON_BEGIN_LIST -> push_state LIST; get_list_item
** JSON_KEY -> get_value
** JSON_ERROR -> JSON_ERROR
** JSON_EOF -> JSON_EOF
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
