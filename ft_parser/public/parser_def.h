/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_def.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 21:02:47 by juloo             #+#    #+#             */
/*   Updated: 2016/02/09 12:46:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_DEF_H
# define SYNTAX_DEF_H

# include "ft/ft_hmap.h"
# include "ft/ft_vector.h"
# include "ft/libft.h"

# include "parser.h"

typedef struct s_parser_def		t_parser_def;
typedef struct s_parser_def_t	t_parser_def_t;

/*
** ========================================================================== **
** Parser def
** -
** Struct used to declare a parser
*/

struct			s_parser_def
{
	t_sub			name;
	void			*data;
	bool			(*f)(t_parse_data *);
	t_vector		parents;
	t_vector		tokens;
	t_vector		match;
};

struct			s_parser_def_t
{
	t_sub			token;
	void			*data;
	char const		*parser;
	bool			end;
};

# define PARSER_DEF_T(...)			VECTOR(t_parser_def_t, ##__VA_ARGS__)
# define PARSER_T(N,DATA,...)		{.token=SUBC(N), (DATA), ##__VA_ARGS__}
# define PARSER_DEF(N,DATA,F,...)	{SUBC(N), (DATA), (F), __VA_ARGS__}
# define PARSER_INHERIT(...)		.parents=VECTOR(char const*, __VA_ARGS__)

bool			build_parser(t_hmap *dst, t_vector const *parsers);

#endif
