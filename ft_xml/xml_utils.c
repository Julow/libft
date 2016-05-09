/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 12:53:44 by juloo             #+#    #+#             */
/*   Updated: 2016/05/09 16:39:51 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xml_parser.h"

bool		is_xml_name_char(char c, void *env)
{
	if (IS(c, IS_SPACE) || c == '>')
		return (true);
	IGNORE(env);
	return (false);
}

void		xml_parse_spaces(t_xml_parser *xml)
{
	char		c;

	while (IS(c = IN_PEEK(xml->in), IS_SPACE))
	{
		xml->in->buff_i++;
		if (c == '\n')
			xml->line++;
	}
}

t_xml_token	xml_parse_comment(t_xml_parser *xml)
{
	char		c;

	while (true)
	{
		if (!IN_REFRESH(xml->in))
		{
			ft_xml_error(xml, SUBC("Unexpected EOF"));
			return (XML_TOKEN_ERROR);
		}
		if ((c = IN_READ(xml->in)) == '-'
			&& (c = IN_READ(xml->in)) == '-')
		{
			while (IN_READ_IF(xml->in, '-'))
				;
			if (IN_READ_IF(xml->in, '>'))
				break ;
		}
		else if (c == '\n')
			xml->line++;
	}
	return (xml_next_end(xml));
}
