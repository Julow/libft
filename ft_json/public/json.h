/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:20:01 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/14 23:30:38 by juloo            ###   ########.fr       */
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
	JSON_KEY,
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
** token		=> Current token
** value_type	=> Current value's type (only if token = JSON_VALUE)
** val_int		=> Int value (only if value_type = JSON_VALUE_INT)
** val_float	=> Float value (only if value_type = JSON_VALUE_FLOAT)
** val_bool		=> Bool value (only if value_type = JSON_VALUE_BOOL)
** -
** JSON_KEY_STRING(P+)		Return the current key name (if token = JSON_KEY)
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
	t_json_token	token;
	t_json_value_t	value_type;
	union {
		int32_t			val_int;
		float			val_float;
		bool			val_bool;
	};
};

# define JSON_PARSER(IN)		((t_json_parser){(IN), DSTR0(), 0, JSON_KEY, 0, {}})

# define JSON_KEY_STRING(P)		(JSON_VAL_STRING(P))
# define JSON_VAL_STRING(P)		(SUB_FOR(DSTR_SUB((P)->buff), (P)->state_len))
# define JSON_VAL_NUMBER(P)		(((P)->value_type == JSON_VALUE_INT) ? (float)(P)->val_int : (P)->val_float)
# define JSON_ERROR_STRING(P)	(JSON_VAL_STRING(P))

/*
** Parse until the next token
** Return true on success, false on EOF or error
*/
bool		ft_json_next(t_json_parser *p);

#endif
