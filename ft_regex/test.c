/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 19:25:26 by juloo             #+#    #+#             */
/*   Updated: 2016/01/03 14:35:04 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "ft/regex.h"

#include "regex_internal.h"

static void		print_regex(t_reg const *reg, int indent)
{
	t_reg const		*r;

	while (reg != NULL)
	{
		r = reg;
		ft_printf("%.*c?", indent * 4, ' ');
		if (r->flags & REG_F_NOT)
			ft_printf("!");
		if (r->flags & REG_F_ICASE)
			ft_printf("i");
		if (r->flags & REG_F_ASSERT)
			ft_printf("=");
		if (r->flags & REG_F_MINIMAL)
			ft_printf("-");
		if (r->flags & REG_F_UNUSED)
			ft_printf("#");
		while (true)
		{
			ft_printf("%u,%u", r->min, r->max);
			switch (r->type)
			{
			case REG_T_STR:
				ft_printf("'%ts'", *(t_sub const*)ENDOF(r));
				break ;
			case REG_T_SET:
				{
					char			c;
					char			tmp;
					c = 0;
					while (c < 127)
					{
						if (BITARRAY_GET(ENDOF((t_is const*)ENDOF(r)), c))
						{
							tmp = c++;
							while (c < 127
								&& BITARRAY_GET(ENDOF((t_is const*)ENDOF(r)), c))
								c++;
							c--;
							if (tmp < c)
								ft_printf("[%#c-%#c]", tmp, c);
							else
								ft_printf("[%#c]", c);
						}
						c++;
					}
					ft_printf("<");
					if (((*(t_is const*)ENDOF(r)) & IS_PRINT) == IS_PRINT)
						ft_printf(".");
					if (((*(t_is const*)ENDOF(r)) & IS_ALPHA) == IS_ALPHA)
						ft_printf("a");
					if (((*(t_is const*)ENDOF(r)) & IS_LOWER) == IS_LOWER)
						ft_printf("l");
					if (((*(t_is const*)ENDOF(r)) & IS_UPPER) == IS_UPPER)
						ft_printf("u");
					if (((*(t_is const*)ENDOF(r)) & IS_DIGIT) == IS_DIGIT)
						ft_printf("d");
					if (((*(t_is const*)ENDOF(r)) & IS_ALNUM) == IS_ALNUM)
						ft_printf("n");
					if (((*(t_is const*)ENDOF(r)) & IS_SPACE) == IS_SPACE)
						ft_printf("s");
					if (((*(t_is const*)ENDOF(r)) & IS_WORD) == IS_WORD)
						ft_printf("w");
					ft_printf(">");
				}
				break ;
			case REG_T_GROUP:
				ft_printf("(%n");
				print_regex(*((t_reg *const*)ENDOF(r)), indent + 1);
				ft_printf("%.*c)", indent * 4, ' ');
				break ;
			case REG_T_EOL:
				ft_printf("EOL");
				break ;
			case REG_T_WBOUND:
				ft_printf("WBOUND");
				break ;
			default:
				ft_printf("??");
			}
			if ((r = r->or_next) == NULL)
				break ;
			ft_printf("|");
		}
		ft_printf("%n");
		reg = reg->next;
	}
}

static void		test_regex(t_regex const *regex, char const *str)
{
	t_sub const		test_sub = ft_sub(str, 0, -1);
	t_sub			match;
	t_sub			captures[regex->capture_count];
	uint32_t		match_count;
	uint32_t		i;

	ft_printf("test: '%ts'%n", test_sub);
	match_count = 0;
	match = SUB(test_sub.str, 0);
	while (true)
	{
		ft_bzero(captures, sizeof(t_sub) * regex->capture_count);
		if (!ft_rmatch(test_sub, &match, regex, captures))
			break ;
		ft_printf("match: '%ts'%n", match);
		i = 0;
		while (i < regex->capture_count)
		{
			ft_printf("capture#%u: '%ts'%n", i, captures[i]);
			i++;
		}
		match_count++;
	}
	if (match_count == 0)
		ft_printf("0 match%n");
}

static bool		test_test(char const *regex_str, char const *str)
{
	t_regex			regex;

	ft_printf("[%s] '%s' ", regex_str, str);
	if (!ft_rcompile(&regex, ft_sub(regex_str, 0, -1)))
		return (ft_printf("ERROR%n"), false);

	t_sub const		test_sub = ft_sub(str, 0, -1);
	uint32_t		match_count;
	uint32_t		i;
	t_sub			match;
	t_sub			captures[regex.capture_count];

	match_count = 0;
	match = SUB(test_sub.str, 0);
	while (true)
	{
		ft_bzero(captures, S(t_sub, regex.capture_count));
		if (!ft_rmatch(test_sub, &match, &regex, captures))
			break ;
		ft_printf("%ts", match);
		i = 0;
		while (i < regex.capture_count)
			ft_printf(":%ts", captures[i++]);
		ft_printf(";");
		match_count++;
	}
	if (match_count == 0)
		ft_printf("NO MATCH");
	ft_printf("%n");

	ft_rdestroy(&regex);
	return (true);
}

int				main(int argc, char **argv)
{
	t_regex			regex;

	if (argc <= 1)
	{
		test_test("abc", "abc");
		test_test("lol", "abc");
		test_test("a", "abc");
		test_test("?w", "abc");
		test_test("?^?w", "abc");
		test_test("?w?$", "abc");
		test_test("?##{FLOAT}(?+d?\?(.?*d))<?{FLOAT}>", "<5>");
		test_test("?##{FLOAT}(?+d?\?(.?*d))<?{FLOAT}>", "<5.>");
		test_test("?##{FLOAT}(?+d?\?(.?*d))<?{FLOAT}>", "<5.5>");
		test_test("?##{FLOAT}(?+d?\?(.?*d))<?{FLOAT}>", "<7415.587>");
		test_test("?##{FLOAT}(?+d?\?(.?*d))<?&{FLOAT}>", "<7415>");
		test_test("?##{FLOAT}(?+d?\?(.?*d))<?=&{FLOAT}", "<7415>");
		test_test("?*&d?-*&w?+&a?+&d", "42lol42");
		test_test("?*&[0-9]?-*&[a-zA-Z0-9]?+&[a-z]?+&[0-9]", "42lol42");
		test_test("?-*&d?*&w?+&a?+&d", "42lol42");
		test_test("?-*&d?-*&w?+&a?+&d", "42lol42");
		return (0);
	}
	if (!ft_rcompile(&regex, ft_sub(argv[1], 0, -1)))
		return (1);
	print_regex(regex.reg, 0);
	if (argc > 2)
		test_regex(&regex, argv[2]);
	ft_rdestroy(&regex);
	return (0);
}
