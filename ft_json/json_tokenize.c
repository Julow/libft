/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_tokenize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:58:00 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/15 00:02:02 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_json_parser.h"

static t_json_p_token	json_tokenize_error(t_json_parser *p, t_sub str)
{
	json_parse_error(p, str);
	return (JSON_P_ERROR);
}

static t_json_p_token	json_tokenize_string(t_json_parser *p)
{
	char			c;

	p->buff.length = p->state_len;
	while (true)
	{
		if (!IN_REFRESH(p->in))
			return (json_tokenize_error(p, SUBC("Unexpected EOF")));
		c = p->in->buff[p->in->buff_i++]; // TODO: ft::in: unsafe read
		if (c == '"')
			break ;
		if (c == '\\')
		{
			if (!IN_REFRESH(p->in))
				return (json_tokenize_error(p, SUBC("Unexpected EOF")));
			c = p->in->buff[p->in->buff_i++];
		}
		DSTR_APPEND(&p->buff, c);
	}
	return (JSON_P_STRING);
}

static t_json_p_token	json_tokenize_identifier(t_json_parser *p, char prev)
{
	char			c;

	p->buff.length = p->state_len;
	DSTR_APPEND(&p->buff, prev);
	while (true)
	{
		if (!IN_REFRESH(p->in))
			break ;
		c = p->in->buff[p->in->buff_i];
		if (!(IS(c, IS_WORD) || c == '$' || c == '~' || c == '-' || c == '+'
			|| c == '<' || c == '>' || c == '?' || c == '.'))
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
	return (json_tokenize_error(p, SUBC("Unexpected EOF")));
}

static t_json_p_token	json_tokenize_comment(t_json_parser *p)
{
	char			c;

	if (!IN_REFRESH(p->in))
		return (json_tokenize_error(p, SUBC("Syntax error")));
	c = p->in->buff[p->in->buff_i++];
	if (c == '/')
	{
		while (IN_REFRESH(p->in) && p->in->buff[p->in->buff_i++] != '\n')
			;
		return (json_tokenize(p));
	}
	else if (c == '*')
		return (json_tokenize_comment_multiline(p));
	return (json_tokenize_error(p, SUBC("Syntax error")));
}

t_json_p_token			json_tokenize(t_json_parser *p)
{
	char			c;

	while (true)
	{
		if (!IN_REFRESH(p->in))
			return (JSON_P_EOF);
		c = p->in->buff[p->in->buff_i++];
		if (!IS(c, IS_SPACE))
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
	if (IS(c, IS_WORD) || c == '$' || c == '~' || c == '-' || c == '+'
			|| c == '<' || c == '>' || c == '?' || c == '.')
		return (json_tokenize_identifier(p, c));
	if (c == '/')
		return (json_tokenize_comment(p));
	return (json_tokenize_error(p, SUBC("Invalid syntax")));
}
