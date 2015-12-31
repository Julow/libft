/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 19:25:26 by juloo             #+#    #+#             */
/*   Updated: 2015/12/31 18:28:13 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "ft/regex.h"

#include "regex_internal.h"

// ?#{FLOAT}(?+d??(.?*d)), ?{FLOAT}, ?{FLOAT}

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
			case REG_T_IS:
				ft_printf("<%0.8b>", *(t_is const*)ENDOF(r));
				break ;
			case REG_T_SET:
				{
					char			c;
					char			tmp;
					c = 0;
					while (c < 127)
					{
						if (BITARRAY_GET(((t_bits const*)ENDOF(r)), c))
						{
							tmp = c++;
							while (c < 127
								&& BITARRAY_GET(((t_bits const*)ENDOF(r)), c))
								c++;
							c--;
							if (tmp < c)
								ft_printf("[%#c-%#c]", tmp, c);
							else
								ft_printf("[%#c]", c);
						}
						c++;
					}
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
			case REG_T_VA:
				ft_printf(":%d;%d", ((t_reg_va const*)r)->index,
					((t_reg_va const*)r)->type);
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

int				main(int argc, char **argv)
{
	t_regex			regex;

	if (argc <= 1)
		return (ft_printf("Not enough argument%n"), 1);
	if (!ft_rcompile(&regex, ft_sub(argv[1], 0, -1)))
		return (1);
	print_regex(regex.reg, 0);
	ft_rdestroy(&regex);
	return (0);
}