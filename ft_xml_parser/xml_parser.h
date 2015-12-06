/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 21:21:33 by juloo             #+#    #+#             */
/*   Updated: 2015/12/06 23:40:05 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XML_PARSER_H
# define XML_PARSER_H

# include "ft/ft_xml_parser.h"

t_xml_token	xml_next_start(t_xml_parser *xml);
t_xml_token	xml_next_end(t_xml_parser *xml);
t_xml_token	xml_next_error(t_xml_parser *xml);

#endif
