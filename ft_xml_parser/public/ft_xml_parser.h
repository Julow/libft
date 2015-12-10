/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xml_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 16:27:41 by juloo             #+#    #+#             */
/*   Updated: 2015/12/10 18:08:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_XML_PARSER_H
# define FT_XML_PARSER_H

# include "ft/libft.h"
# include "ft/ft_in.h"
# include "ft/ft_dstr.h"

typedef struct s_xml_parser	t_xml_parser;
typedef enum e_xml_token	t_xml_token;

/*
** ========================================================================== **
** XML Parser
*/

enum		e_xml_token
{
	XML_TOKEN_START,
	XML_TOKEN_END,
	XML_TOKEN_PARAM,
	XML_TOKEN_EOF,
	XML_TOKEN_ERROR
};

struct		s_xml_parser
{
	t_in		*in;
	uint32_t	line;
	t_dstr		tmp_str;
	uint32_t	tmp_offset;
	t_xml_token	last;
};

/*
** Init a xml parser from an in stream
*/
# define XML_PARSER(IN)	((t_xml_parser){(IN), 1, DSTR0(), 0, XML_TOKEN_END})

/*
** Read the next token
*/
t_xml_token	ft_xml_next(t_xml_parser *xml);

/*
** Return markup name after XML_TOKEN_START
** Return param name after XML_TOKEN_PARAM
*/
t_sub		ft_xml_name(t_xml_parser const *xml);

/*
** Return param value after XML_TOKEN_PARAM
** Return error string after XML_TOKEN_ERROR
*/
t_sub		ft_xml_value(t_xml_parser const *xml);

/*
** Just free the internal string
*/
void		ft_xml_stop(t_xml_parser *xml);

#endif
