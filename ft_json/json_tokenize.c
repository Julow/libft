/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_tokenize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:58:00 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/19 18:07:23 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_json_parser.h"

/*
** ?omg
** import re
** JSON_IDENTIFIER = '[\w\\+\\-\\.\\?#$%<=>@~]'
** out("\n")
** out("uint32_t const		g_identifier_chars[] = {\n")
** for i in range(0, 256, 32):
** 	d = 0
** 	for c in range(32):
** 		if re.match(JSON_IDENTIFIER, chr(c + i)): d |= 1 << c
** 	out("	0x%08x,\n" % d)
** out("};\n")
** out("\n")
*/

uint32_t const		g_identifier_chars[] = {
	0x00000000,
	0xf3ff6838,
	0x87ffffff,
	0x47fffffe,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
};

/*
** ?end
*/

static t_json_p_token	json_tokenize_string(t_json_parser *p)
{
	char			c;

	p->buff.length = p->key_len;
	while (true)
	{
		if (!IN_REFRESH(p->in))
			return (ft_json_fail(p, SUBC("Unexpected EOF")), JSON_P_ERROR);
		c = p->in->buff[p->in->buff_i++]; // TODO: ft::in: unsafe read
		if (c == '"')
			break ;
		if (c == '\\')
		{
			if (!IN_REFRESH(p->in))
				return (ft_json_fail(p, SUBC("Unexpected EOF")), JSON_P_ERROR);
			c = p->in->buff[p->in->buff_i++];
		}
		DSTR_APPEND(&p->buff, c);
	}
	return (JSON_P_STRING);
}

static t_json_p_token	json_tokenize_identifier(t_json_parser *p, char prev)
{
	char			c;

	p->buff.length = p->key_len;
	DSTR_APPEND(&p->buff, prev);
	while (true)
	{
		if (!IN_REFRESH(p->in))
			break ;
		c = p->in->buff[p->in->buff_i];
		if (!BITARRAY_GET(g_identifier_chars, c))
			break ;
		p->in->buff_i++;
		DSTR_APPEND(&p->buff, c);
	}
	return (JSON_P_IDENTIFIER);
}

static t_json_p_token	json_tokenize_comment_multiline(t_json_parser *p)
{
	while (IN_REFRESH(p->in))
	{
		if (p->in->buff[p->in->buff_i++] == '*')
		{
			if (!IN_REFRESH(p->in))
				break ;
			if (p->in->buff[p->in->buff_i] == '/')
				return (json_tokenize(p));
		}
	}
	return (ft_json_fail(p, SUBC("Unexpected EOF")), JSON_P_ERROR);
}

static t_json_p_token	json_tokenize_comment(t_json_parser *p)
{
	char			c;

	if (!IN_REFRESH(p->in))
		return (ft_json_fail(p, SUBC("Syntax error")), JSON_P_ERROR);
	c = p->in->buff[p->in->buff_i++];
	if (c == '/')
	{
		while (IN_REFRESH(p->in) && p->in->buff[p->in->buff_i++] != '\n')
			;
		return (json_tokenize(p));
	}
	else if (c == '*')
		return (json_tokenize_comment_multiline(p));
	return (ft_json_fail(p, SUBC("Syntax error")), JSON_P_ERROR);
}

t_json_p_token			json_tokenize(t_json_parser *p)
{
	char			c;

	while (true)
	{
		if (!IN_REFRESH(p->in))
			return (JSON_P_EOF);
		c = p->in->buff[p->in->buff_i++];
		if (!IS(c, IS_WHITESPACE))
			break ;
	}
	// TODO: improve
	if (c == '{')
		return (JSON_P_BRACE_OPEN);
	if (c == '}')
		return (JSON_P_BRACE_CLOSE);
	if (c == '[')
		return (JSON_P_SQUARE_OPEN);
	if (c == ']')
		return (JSON_P_SQUARE_CLOSE);
	if (c == ',')
		return (JSON_P_COMMA);
	if (c == ':')
		return (JSON_P_COLON);
	if (c == '"')
		return (json_tokenize_string(p));
	if (BITARRAY_GET(g_identifier_chars, c))
		return (json_tokenize_identifier(p, c));
	if (c == '/')
		return (json_tokenize_comment(p));
	return (ft_json_fail(p, SUBC("Invalid syntax")), JSON_P_ERROR);
}
