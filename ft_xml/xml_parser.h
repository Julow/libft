/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 21:21:33 by juloo             #+#    #+#             */
/*   Updated: 2016/02/20 14:50:19 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XML_PARSER_H
# define XML_PARSER_H

# include "ft/ft_xml.h"

t_xml_token	xml_next_start(t_xml_parser *xml);
t_xml_token	xml_next_end(t_xml_parser *xml);
t_xml_token	xml_next_error(t_xml_parser *xml);

bool		is_xml_name_char(char c, void *env);
void		xml_parse_spaces(t_xml_parser *xml);
t_xml_token	xml_parse_comment(t_xml_parser *xml);

t_xml_token	xml_parse_error(t_xml_token *xml, t_sub error);

#endif
