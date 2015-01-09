/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_g.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 17:20:17 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 11:35:40 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"
#include <stdlib.h>

void			flag_g(t_string *out, t_opt *opt, va_list *ap)
{
	long double		g;
	t_string		str;

	if (!opt->preci_set)
		opt->preci = 6;
	g = get_float_arg(opt, ap);
	ft_stringini(&str);
	if (HASF('+') && g >= 0)
		ft_stringaddc(&str, '+');
	else if (HASF(' ') && g >= 0)
		ft_stringaddc(&str, ' ');
	if (EXP(g) < -4 || EXP(g) >= opt->preci)
	{
		ft_stringaddde(&str, g, opt->preci);
	}
	else
		ft_stringaddd(&str, g, opt->preci);
	if (opt->format->name == 'G')
		ft_strupper(str.content);
	ft_stringtrimc(&str, "0.");
	add_string(out, str.content, str.length, opt);
	free(str.content);
}
