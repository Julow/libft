/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:20:01 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/19 18:03:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JSON_H
# define JSON_H

# include "ft/ft_dstr.h"
# include "ft/ft_in.h"
# include "ft/libft.h"

typedef enum e_json_token		t_json_token;
typedef enum e_json_value_t		t_json_value_t;
typedef struct s_json_parser	t_json_parser;

/*
** ========================================================================== **
** JSON Parser
*/

enum		e_json_token
{
	JSON_BEGIN_DICT,
	JSON_BEGIN_LIST,
	JSON_END,
	JSON_VALUE,
	JSON_ERROR,
	JSON_EOF,
};

enum		e_json_value_t
{
	JSON_VALUE_STRING,
	JSON_VALUE_INT,
	JSON_VALUE_FLOAT,
	JSON_VALUE_BOOL,
	JSON_VALUE_NULL,
};

/*
** in			=> Input stream
** buff			=> (Internal) buffer
** state_len	=> (Interval) part of the buffer that store states
** key_len		=> (Interval) part of the buffer that store keys
** token		=> Current token
** value_type	=> Current value's type (only if token = JSON_VALUE)
** val_int		=> Int value (only if value_type = JSON_VALUE_INT)
** val_float	=> Float value (only if value_type = JSON_VALUE_FLOAT)
** val_bool		=> Bool value (only if value_type = JSON_VALUE_BOOL)
** -
** JSON_KEY_STRING(P+)		Return the current key name (only if currently in a dict)
** JSON_VAL_STRING(P+)		Return the current string value (if token = JSON_VALUE)
** JSON_VAL_NUMBER(P+)		Return the current float value
** 								(JSON_VALUE_INT or JSON_VALUE_FLOAT)
** JSON_ERROR_STRING(P+)	Return the error string (if token = JSON_ERROR)
*/
struct		s_json_parser
{
	t_in			*in;
	t_dstr			buff;
	uint32_t		state_len;
	uint32_t		key_len;
	t_json_token	token;
	t_json_value_t	value_type;
	union {
		int32_t			val_int;
		float			val_float;
		bool			val_bool;
	};
};

# define JSON_PARSER(IN)		((t_json_parser){(IN), DSTR0(), -1, 0, 0, 0, {}})

# define JSON_KEY_STRING(P)		(SUB((P)->buff.str + (P)->state_len, (P)->key_len - (P)->state_len))
# define JSON_VAL_STRING(P)		(SUB_FOR(DSTR_SUB((P)->buff), (P)->key_len))
# define JSON_VAL_NUMBER(P)		(((P)->value_type == JSON_VALUE_INT) ? (float)(P)->val_int : (P)->val_float)
# define JSON_ERROR_STRING(P)	(JSON_VAL_STRING(P))

/*
** Parse until the next token
** Return true on success, false on EOF or error
*/
bool		ft_json_next(t_json_parser *p);

/*
** Stop the parsing and report the error 'err'
** Next call to ft_json_next will fail with the token JSON_ERROR
** Return false
*/
bool		ft_json_fail(t_json_parser *p, t_sub err);

/*
** Destroy the json_parser object
** (Do not clear 'in')
*/
void		ft_json_parser_clear(t_json_parser *p);

#endif
