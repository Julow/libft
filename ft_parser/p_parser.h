/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parser.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 18:45:07 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/18 15:57:31 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_PARSER_H
# define P_PARSER_H

# include "ft/ft_hmap.h"
# include "ft/parser.h"
# include "ft/parser_def.h"

typedef struct s_subparser_resolver		t_subparser_resolver;

/*
** ========================================================================== **
*/

struct			s_subparser_resolver
{
	t_parser		*parser;
	t_hmap			*map;
	t_vector const	*parsers;
};

bool			exec_match(t_parse_data *p);

bool			exec_token(t_parse_data *p);

/*
** -
*/

void			build_tokens(t_parser *parser, t_parser_def const *def);

void			build_inheritance(t_hmap *map, t_parser *parser,
					t_vector const *parsers, t_parser_def const *def);

void			add_token(t_parser *parser, t_sub token_str,
					t_parser_token token);

t_parser		*get_parser(t_sub name, t_hmap *map, t_vector const *parsers);

/*
** TODO: remove this shit
*/
bool			resolve_subparsers(t_parser *parser, t_hmap *map,
					t_vector const *parsers);

#endif
