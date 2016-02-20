/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xml.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 16:27:41 by juloo             #+#    #+#             */
/*   Updated: 2016/02/20 14:51:34 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_XML_PARSER_H
# define FT_XML_PARSER_H

# include "ft/ft_dstr.h"
# include "ft/ft_in.h"
# include "ft/libft.h"

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
	t_xml_token	token;
};

/*
** Init a xml parser from a stream
*/
# define XML_PARSER(IN)	((t_xml_parser){(IN), 1, DSTR0(), 0, XML_TOKEN_END})

/*
** Read the next token
** Return true on success, false on EOF or ERROR
** 'xml->token' is set to the current token type
*/
bool		ft_xml_next(t_xml_parser *xml);

/*
** Return markup name after XML_TOKEN_START
** Return param name after XML_TOKEN_PARAM
*/
t_sub		ft_xml_name(t_xml_parser const *xml);

/*
** Return param value after XML_TOKEN_PARAM
** TODO: Return error string after XML_TOKEN_ERROR
*/
t_sub		ft_xml_value(t_xml_parser const *xml);

/*
** Clear the internal buffer
*/
void		ft_xml_clear(t_xml_parser *xml);

#endif
