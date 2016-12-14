/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:20:01 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/14 19:17:51 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JSON_H
# define JSON_H

# include "ft/ft_dstr.h"
# include "ft/ft_in.h"
# include "ft/libft.h"

typedef enum e_json_token		t_json_token;
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
	JSON_STRING,
	JSON_BOOL,
	JSON_NUMBER,
	JSON_NULL,
	JSON_ERROR,
	JSON_EOF,
};

struct		s_json_parser
{
	t_in			*in;
	t_dstr			buff;
	uint32_t		state_len;
	t_json_token	token;
};

t_json_token	ft_json_next(t_json_parser *p);

#endif
