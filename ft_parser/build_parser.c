/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 20:06:51 by juloo             #+#    #+#             */
/*   Updated: 2016/02/17 11:29:29 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/parser.h"
#include "ft/parser_def.h"

static t_parser	*get_parser(t_sub name, t_hmap *map, t_vector const *parsers);

static bool		parser_parse_ignore(t_parse_data *p)
{
	while (ft_parse_token(p))
		;
	return (PARSE_EOF(p));
}

static void		add_token(t_parser *parser, t_sub token_str, void *data,
					t_parser *sub_parser, bool end_token)
{
	t_token_def		token_def;
	t_parser_token	*token;

	token = NEW(t_parser_token);
	*token = (t_parser_token){data, sub_parser, end_token};
	token_def.sub = token_str;
	token_def.data = token;
	ft_token_map(&parser->token_map, &token_def);
}

static void		add_match(t_parser *parser, t_sub pattern, void *data,
					t_parser *sub_parser, bool end_token)
{
	t_parser_match	match;
	t_regex_err		err;

	if (!ft_rcompile(&match.regex, pattern, &err))
	{
		ft_printf("%ts: '%ts'\n%.*c^%n",
			err.str, pattern, err.str.length + 3, ' ');
		return ;
	}
	match.token = (t_parser_token){data, sub_parser, end_token};
	ft_vpush(&parser->match, &match, 1);
}

static bool		has_dupplicated_token(t_token_def const *token,
					t_sub const *name, void *env)
{
	if (SUB_EQU(token->sub, *name))
		return (false);
	return (true);
	(void)env;
}

static bool		inherit_tokens(t_token_def const *token, t_parser *parser)
{
	t_parser_token *const	p_token = token->data;

	if (ft_bst_getall(&parser->token_map.tokens, &token->sub,
			&has_dupplicated_token, NULL))
		add_token(parser, token->sub, p_token->data, p_token->parser, p_token->end);
	return (true);
}

static void		inherit_match(t_parser *parser, t_parser const *parent)
{
	uint32_t				i;
	t_parser_match			match;
	t_parser_match const	*m;

	i = 0;
	while (i < parent->match.length)
	{
		m = VECTOR_GET(parent->match, i);
		match.regex = m->regex; // TODO: dup regex
		match.token = (t_parser_token){m->token.data, m->token.parser, false};
		ft_vpush(&parser->match, &match, 1);
		i++;
	}
}

static t_parser	*build(t_hmap *map, t_vector const *parsers,
					t_parser_def const *def)
{
	t_parser				*parser;
	t_parser				*parent;
	t_parser_def_t const	*token;
	uint32_t				i;

	ft_hmapputp(map, def->name, NULL);
	parser = ft_hmapput(map, def->name, NULL, sizeof(t_parser)).value;
	parser->data = def->data;
	parser->f = (def->f == NULL) ? &parser_parse_ignore : def->f;
	parser->token_map = TOKEN_MAP();
	parser->match = VECTOR(t_parser_match);
	parser->resolved = false;
	i = 0;
	while (i < def->tokens.length)
	{
		token = VECTOR_GET(def->tokens, i);
		add_token(parser, token->token, token->data,
			V(token->parser), token->end);
		i++;
	}
	i = 0;
	while (i < def->match.length)
	{
		token = VECTOR_GET(def->match, i);
		add_match(parser, token->token, token->data,
			V(token->parser), token->end);
		i++;
	}
	i = 0;
	while (i < def->parents.length)
	{
		if ((parent = get_parser(ft_sub(*(void**)VECTOR_GET(def->parents, i++), 0, -1),
				map, parsers)) == NULL)
			continue ;
		ft_bst_iter(&parent->token_map.tokens, &inherit_tokens, parser);
		inherit_match(parser, parent);
	}
	return (parser);
}

static t_parser	*get_parser(t_sub name, t_hmap *map, t_vector const *parsers)
{
	t_hpair				tmp;
	t_parser_def const	*def;
	uint32_t			i;

	if ((tmp = ft_hmapget(map, name)).key != NULL)
	{
		if (tmp.value == NULL)
			ft_dprintf(2, "Inherit loop: %ts%n", name);
		return (tmp.value);
	}
	i = 0;
	while (i < parsers->length)
	{
		def = VECTOR_GET(*parsers, i);
		if (def->name.length == name.length
			&& ft_memcmp(def->name.str, name.str, name.length) == 0)
			return (build(map, parsers, def));
		i++;
	}
	ft_dprintf(2, "Unknown parser: %ts%n", name);
	return (NULL);
}

/*
** ========================================================================== **
** Sub parser resolver
** -
** TODO: remove this shit
*/

struct			s_subparser_resolver
{
	t_parser		*parser;
	t_hmap			*map;
	t_vector const	*parsers;
};

static bool		resolve_token_subparsers(t_token_def *def,
					struct s_subparser_resolver *s)
{
	t_parser_token	*t;

	t = def->data;
	if (t->parser != NULL)
	{
		if ((t->parser = get_parser(ft_sub((char const*)t->parser, 0, -1),
			s->map, s->parsers)) == NULL)
			return (false);
	}
	return (true);
}

static bool		resolve_subparsers(t_parser *parser, t_hmap *map,
					t_vector const *parsers)
{
	struct s_subparser_resolver	s;
	uint32_t		i;
	t_parser_token	*t;

	s = (struct s_subparser_resolver){parser, map, parsers};
	if (!ft_bst_iter(&parser->token_map.tokens, &resolve_token_subparsers, &s))
		return (false);
	i = 0;
	while (i < parser->match.length)
	{
		t = &(((t_parser_match*)VECTOR_GET(parser->match, i++))->token);
		if (t->parser != NULL)
		{
			if ((t->parser = get_parser(ft_sub((char const*)t->parser, 0, -1),
				map, parsers)) == NULL)
				return (false);
		}
	}
	return (true);
}

/*
** ========================================================================== **
*/

bool			build_parser(t_hmap *dst, t_vector const *parsers)
{
	t_parser_def const *const	defs = parsers->data;
	t_parser					*p;
	uint32_t					i;

	i = 0;
	while (i < parsers->length)
	{
		if (ft_hmapget(dst, defs[i].name).key == NULL
			&& build(dst, parsers, defs + i) == NULL)
			return (false);
		i++;
	}
	i = 0;
	while (i < parsers->length)
	{
		p = ft_hmapget(dst, defs[i].name).value;
		if (!p->resolved && !resolve_subparsers(p, dst, parsers))
			ft_printf("Fail resolving dependencies for %ts%n", defs[i].name);
		i++;
	}
	return (true);
}
