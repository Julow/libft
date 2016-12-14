/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:02:43 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/14 19:30:57 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_json_parser.h"

// get_key ->
// 	IDENTIFIER		-> JSON_KEY
// 	STRING			-> JSON_KEY
// 	?				-> fail

// get_value ->
// 	BRACE_OPEN		-> JSON_BEGIN_DICT
// 	SQUARE_OPEN		-> JSON_BEGIN_LIST
// 	STRING			-> JSON_STRING
// 	IDENTIFIER		-> JSON_BOOL|JSON_NUMBER|JSON_NULL
// 	?				-> fail

// JSON_BEGIN_DICT		-> push_state DICT; get_key
// JSON_BEGIN_LIST		-> push_state LIST; get_value

// JSON_END			->
// JSON_STRING			||
// JSON_BOOL			||
// JSON_NUMBER			||
// JSON_NULL			-> ???

// JSON_ERROR			-> JSON_ERROR
// JSON_EOF			-> JSON_EOF

t_json_token	ft_json_next(t_json_parser *p)
{
}
