/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xml_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 17:08:50 by juloo             #+#    #+#             */
/*   Updated: 2015/12/07 00:30:13 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_xml_parser.h"
#include "xml_parser.h"

static t_xml_token (*g_next_f[])(t_xml_parser *xml) = {
	[XML_TOKEN_START] = &xml_next_start,
	[XML_TOKEN_PARAM] = &xml_next_start,
	[XML_TOKEN_END] = &xml_next_end,
	[XML_TOKEN_EOF] = &xml_next_error,
	[XML_TOKEN_ERROR] = &xml_next_error,
};

t_xml_token	ft_xml_next(t_xml_parser *xml)
{
	t_xml_token	token;

	token = g_next_f[xml->last](xml);
	xml->last = token;
	return (token);
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

void		ft_xml_stop(t_xml_parser *xml)
{
	ft_dstrclear(&(xml->tmp_str));
}
