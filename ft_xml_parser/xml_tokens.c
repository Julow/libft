/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 21:20:31 by juloo             #+#    #+#             */
/*   Updated: 2015/12/10 19:14:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_xml_parser.h"
#include "xml_parser.h"

static void	xml_parse_spaces(t_xml_parser *xml)
{
	char		c;

	while (IS(c = IN_PEEK(xml->in), IS_SPACE))
	{
		xml->in->buff_i++;
		if (c == '\n')
			xml->line++;
	}
}

t_xml_token	xml_next_start(t_xml_parser *xml)
{
	xml_parse_spaces(xml);
	if (IN_READ_IF(xml->in, '>'))
		return (xml_next_end(xml));
	if (IN_READ_IF(xml->in, '/'))
	{
		xml_parse_spaces(xml);
		if (!IN_READ_IF(xml->in, '>'))
			return (XML_TOKEN_ERROR);
		return (XML_TOKEN_END);
	}
	xml->tmp_str.length = 0;
	if (!ft_readto_not(xml->in, IS_WORD, &(xml->tmp_str)))
		return (XML_TOKEN_ERROR);
	xml_parse_spaces(xml);
	if (!IN_READ_IF(xml->in, '='))
		return (XML_TOKEN_ERROR);
	xml_parse_spaces(xml);
	if (!IN_READ_IF(xml->in, '"'))
		return (XML_TOKEN_ERROR);
	xml->tmp_offset = xml->tmp_str.length;
	if (!ft_readto_char(xml->in, '"', &(xml->tmp_str)))
		return (XML_TOKEN_ERROR);
	if (!IN_READ_IF(xml->in, '"'))
		return (XML_TOKEN_ERROR);
	return (XML_TOKEN_PARAM);
}

bool		is_xml_name_char(char c, void *env)
{
	if (IS(c, IS_SPACE) || c == '>')
		return (true);
	IGNORE(env);
	return (false);
}

t_xml_token	xml_next_end(t_xml_parser *xml)
{
	xml_parse_spaces(xml);
	if (!IN_READ_IF(xml->in, '<'))
		return (IN_REFRESH(xml->in) ? XML_TOKEN_ERROR : XML_TOKEN_EOF);
	xml_parse_spaces(xml);
	if (IN_READ_IF(xml->in, '/'))
	{
		xml_parse_spaces(xml);
		if (!ft_readto_char(xml->in, '>', NULL)
			|| !IN_READ_IF(xml->in, '>'))
			return (XML_TOKEN_ERROR);
		return (XML_TOKEN_END);
	}
	if (IN_READ_IF(xml->in, '!'))
	{
		if (!IN_READ_IF(xml->in, '-') || !IN_READ_IF(xml->in, '-'))
			return (XML_TOKEN_ERROR);
		// TODO: parse comment
	}
	xml->tmp_str.length = 0;
	if (!ft_readto_func(xml->in, &is_xml_name_char, NULL, &(xml->tmp_str)))
		return (XML_TOKEN_ERROR);
	xml->tmp_offset = xml->tmp_str.length;
	return (XML_TOKEN_START);
}

t_xml_token	xml_next_error(t_xml_parser *xml)
{
	return (xml->last);
}
