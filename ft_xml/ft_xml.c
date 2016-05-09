/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xml.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 17:08:50 by juloo             #+#    #+#             */
/*   Updated: 2016/05/09 18:23:09 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_xml.h"
#include "xml_parser.h"

typedef t_xml_token		(*t_token_f)(t_xml_parser *xml);

static t_token_f const	g_next_f[] = {
	[XML_TOKEN_START] = &xml_next_start,
	[XML_TOKEN_PARAM] = &xml_next_start,
	[XML_TOKEN_END] = &xml_next_end,
	[XML_TOKEN_EOF] = &xml_next_error,
	[XML_TOKEN_ERROR] = &xml_next_error,
};

bool		ft_xml_next(t_xml_parser *xml)
{
	t_xml_token	token;

	token = g_next_f[xml->token](xml);
	xml->token = token;
	if (token == XML_TOKEN_END)
		xml->level--;
	else if (token == XML_TOKEN_START)
		xml->level++;
	else if (token == XML_TOKEN_EOF && xml->level != 0)
		return (ft_xml_error(xml, SUBC("Unexpected EOF")));
	return (!BOOL_OF(token == XML_TOKEN_END
		|| token == XML_TOKEN_EOF || token == XML_TOKEN_ERROR));
}

t_sub		ft_xml_name(t_xml_parser const *xml)
{
	return (SUB(xml->tmp_str.str, xml->tmp_offset));
}

t_sub		ft_xml_value(t_xml_parser const *xml)
{
	return (SUB(xml->tmp_str.str + xml->tmp_offset,
		xml->tmp_str.length - xml->tmp_offset));
}

bool		ft_xml_error(t_xml_parser *xml, t_sub err)
{
	xml->tmp_str.length = 0;
	xml->tmp_offset = 0;
	xml->token = XML_TOKEN_ERROR;
	ft_dstradd(&xml->tmp_str, err);
	return (false);
}

void		ft_xml_clear(t_xml_parser *xml)
{
	ft_dstrclear(&(xml->tmp_str));
}
