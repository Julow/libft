/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parser.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 18:45:07 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/17 19:14:14 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_PARSER_H
# define P_PARSER_H

# include "ft/parser.h"

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

void			build_tokens(t_parser *parser, t_parser_def const *def);

void			build_inheritance(t_hmap *map, t_parser *parser,
					t_vector const *parsers, t_parser_def const *def);

t_parser		*get_parser(t_sub name, t_hmap *map, t_vector const *parsers);

/*
** TODO: remove this shit
*/
bool			resolve_subparsers(t_parser *parser, t_hmap *map,
					t_vector const *parsers);

#endif
