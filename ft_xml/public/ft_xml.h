/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xml.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 16:27:41 by juloo             #+#    #+#             */
/*   Updated: 2016/03/07 15:13:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_XML_H
# define FT_XML_H

# include "ft/ft_dstr.h"
# include "ft/ft_in.h"
# include "ft/libft.h"

typedef struct s_xml_parser	t_xml_parser;
typedef enum e_xml_token	t_xml_token;

/*
** ========================================================================== **
** XML Parser
** TODO: count line in comments
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
	uint32_t	level;
	t_xml_token	token;
};

/*
** Init a xml parser from a stream
*/
# define XML_PARSER(IN)	((t_xml_parser){(IN), 1, DSTR0(), 0, 0, XML_TOKEN_END})

/*
** Read the next token
** Return true on success, false on END, EOF or ERROR
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
** Return error string after XML_TOKEN_ERROR
*/
t_sub		ft_xml_value(t_xml_parser const *xml);

/*
** Stop parsing
** 'xml->token' is set to XML_TOKEN_ERROR
** Return false
** -
** 'xml->tmp_str' can be modified to build an error msg
*/
bool		ft_xml_error(t_xml_parser *xml, t_sub err);

/*
** Clear the internal buffer
*/
void		ft_xml_clear(t_xml_parser *xml);

/*
** ========================================================================== **
** void		example(t_xml_parser *xml)
** {
** 	// ft_xml_name: markup name
** 	while (ft_xml_next(xml))
** 	{
** 		if (xml->token == XML_TOKEN_START)
** 			example(xml);
** 			// ft_xml_name: markup name
** 		else if (xml->token == XML_TOKEN_PARAM)
** 			;
** 			// ft_xml_name: param name
** 			// ft_xml_value: param value
** 		else
** 			ASSERT(false, "Cannot happen");
** 	}
** 	if (xml->token == XML_TOKEN_END)
** 		; // no error
** 	else if (xml->token == XML_TOKEN_EOF)
** 		; // no error (can only happen for the root loop)
** 	else if (xml->token == XML_TOKEN_ERROR)
** 		; // ft_xml_error has been called
** 		// ft_xml_value: error string
** 	else
** 		ASSERT(false, "Cannot happen");
** }
** ========================================================================== **
*/

#endif
