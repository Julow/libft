/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 21:20:31 by juloo             #+#    #+#             */
/*   Updated: 2016/02/23 18:49:22 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_xml.h"
#include "xml_parser.h"

#define XML_ERROR(XML, ERR)	(ft_xml_error(XML, SUBC(ERR)), XML_TOKEN_ERROR)

t_xml_token	xml_next_start(t_xml_parser *xml)
{
	xml_parse_spaces(xml);
	if (IN_READ_IF(xml->in, '>'))
		return (xml_next_end(xml));
	if (IN_READ_IF(xml->in, '/'))
	{
		xml_parse_spaces(xml);
		if (!IN_READ_IF(xml->in, '>'))
			return (XML_ERROR(xml, "Expecting '>'"));
		return (XML_TOKEN_END);
	}
	xml->tmp_str.length = 0;
	if (!ft_readto_not(xml->in, IS_WORD, &(xml->tmp_str)))
		return (XML_ERROR(xml, "Unexpected EOF"));
	xml_parse_spaces(xml);
	if (!IN_READ_IF(xml->in, '='))
		return (XML_ERROR(xml, "Invalid char"));
	xml_parse_spaces(xml);
	if (!IN_READ_IF(xml->in, '"'))
		return (XML_ERROR(xml, "Expecting '\"'"));
	xml->tmp_offset = xml->tmp_str.length;
	if (!ft_readto_char(xml->in, '"', &(xml->tmp_str))
		|| !IN_READ_IF(xml->in, '"'))
		return (XML_ERROR(xml, "Unexpected EOF"));
	return (XML_TOKEN_PARAM);
}

t_xml_token	xml_next_end(t_xml_parser *xml)
{
	xml_parse_spaces(xml);
	if (!IN_READ_IF(xml->in, '<'))
		return (IN_REFRESH(xml->in) ? XML_ERROR(xml, "Invalid syntax") : XML_TOKEN_EOF);
	xml_parse_spaces(xml);
	if (IN_READ_IF(xml->in, '/'))
	{
		xml_parse_spaces(xml);
		if (!ft_readto_char(xml->in, '>', NULL)
			|| !IN_READ_IF(xml->in, '>'))
			return (XML_ERROR(xml, "Unexpected EOF"));
		return (XML_TOKEN_END);
	}
	if (IN_READ_IF(xml->in, '!'))
	{
		if (!IN_READ_IF(xml->in, '-') || !IN_READ_IF(xml->in, '-'))
			return (XML_ERROR(xml, "Invalid char"));
		return (xml_parse_comment(xml));
	}
	xml->tmp_str.length = 0;
	if (!ft_readto_func(xml->in, &is_xml_name_char, NULL, &(xml->tmp_str)))
		return (XML_ERROR(xml, "Unexpected EOF"));
	xml->tmp_offset = xml->tmp_str.length;
	return (XML_TOKEN_START);
}

t_xml_token	xml_next_error(t_xml_parser *xml)
{
	return (xml->token);
}
