/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:02:43 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/19 18:06:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_json_parser.h"

static t_json_token	get_key(t_json_parser *p)
{
	t_json_p_token		t;

	t = json_tokenize(p);
	if (t == JSON_P_IDENTIFIER || t == JSON_P_STRING)
	{
		if ((t = json_tokenize(p)) == JSON_P_COLON)
		{
			p->key_len = p->buff.length;
			return (json_parse_value(p, json_tokenize(p)));
		}
		if (t == JSON_P_ERROR)
			return (JSON_ERROR);
		if (t == JSON_P_EOF)
			return (ft_json_fail(p, SUBC("Unexpected EOF")), JSON_ERROR);
		return (ft_json_fail(p, SUBC("Unexpected token: Expecting ':'")), JSON_ERROR);
	}
	if (t == JSON_P_BRACE_CLOSE)
		return (JSON_END);
	if (t == JSON_P_ERROR)
		return (JSON_ERROR);
	if (t == JSON_P_EOF)
		return (ft_json_fail(p, SUBC("Unexpected EOF")), JSON_ERROR);
	return (ft_json_fail(p, SUBC("Unexpected token: Expecting '}'")), JSON_ERROR);
}

static t_json_token	get_list_item(t_json_parser *p)
{
	t_json_p_token const	t = json_tokenize(p);

	if (t == JSON_P_SQUARE_CLOSE)
		return (JSON_END);
	return (json_parse_value(p, t));
}

static t_json_token	json_parse_next_error(t_json_parser *p)
{
	return (p->token);
}

static t_json_token	json_parse_next_begin_dict(t_json_parser *p)
{
	p->buff.length = p->state_len;
	DSTR_APPEND(&p->buff, JSON_STATE_DICT);
	p->state_len++;
	p->key_len = p->state_len;
	return (get_key(p));
}

static t_json_token	json_parse_next_begin_list(t_json_parser *p)
{
	p->buff.length = p->state_len;
	DSTR_APPEND(&p->buff, JSON_STATE_LIST);
	p->state_len++;
	p->key_len = p->state_len;
	return (get_list_item(p));
}

static t_json_token	json_parse_next_value(t_json_parser *p)
{
	t_json_p_token		t;

	if (p->state_len == 0)
		return (ft_json_fail(p, SUBC("Unexpected token")), JSON_ERROR);
	t = json_tokenize(p);
	if (t == JSON_P_ERROR)
		return (JSON_ERROR);
	if (t == JSON_P_EOF)
		return (ft_json_fail(p, SUBC("Unexpected EOF")), JSON_ERROR);
	if (p->buff.str[p->state_len - 1] == JSON_STATE_DICT)
	{
		if (t == JSON_P_COMMA)
			return (get_key(p));
		if (t == JSON_P_BRACE_CLOSE)
			return (JSON_END);
		if (t == JSON_P_SQUARE_CLOSE)
			return (ft_json_fail(p, SUBC("Unexpected ']': Expecting '}'")), JSON_ERROR);
	}
	else
	{
		if (t == JSON_P_COMMA)
			return (get_list_item(p));
		if (t == JSON_P_SQUARE_CLOSE)
			return (JSON_END);
		if (t == JSON_P_BRACE_CLOSE)
			return (ft_json_fail(p, SUBC("Unexpected '}': Expecting ']'")), JSON_ERROR);
	}
	return (ft_json_fail(p, SUBC("Syntax error")), JSON_ERROR);
}

static t_json_token	json_parse_next_end(t_json_parser *p)
{
	ASSERT(p->state_len > 0);
	if ((--p->state_len) == 0)
	{
		if (json_tokenize(p) == JSON_P_EOF)
			return (JSON_EOF);
		return (ft_json_fail(p, SUBC("Expecting EOF")), JSON_ERROR);
	}
	p->key_len = p->state_len;
	return (json_parse_next_value(p));
}

static t_json_token	(*const g_json_parse_next[])(t_json_parser*) = {
	[JSON_BEGIN_DICT] = &json_parse_next_begin_dict,
	[JSON_BEGIN_LIST] = &json_parse_next_begin_list,
	[JSON_END] = &json_parse_next_end,
	[JSON_VALUE] = &json_parse_next_value,
	[JSON_ERROR] = &json_parse_next_error,
	[JSON_EOF] = &json_parse_next_error
};

bool				ft_json_next(t_json_parser *p)
{
	if (p->state_len == (uint32_t)-1)
	{
		p->state_len = 0;
		p->token = json_parse_value(p, json_tokenize(p));
	}
	else
	{
		p->key_len = p->state_len;
		p->token = g_json_parse_next[p->token](p);
	}
	return (p->token != JSON_ERROR && p->token != JSON_EOF);
}
