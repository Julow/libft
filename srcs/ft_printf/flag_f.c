/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 17:24:15 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 11:35:42 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"
#include <stdlib.h>

void			flag_f(t_string *out, t_opt *opt, va_list *ap)
{
	long double		f;
	t_string		str;

	f = get_float_arg(opt, ap);
	ft_stringini(&str);
	if (HASF('+') && f >= 0)
		ft_stringaddc(&str, '+');
	else if (HASF(' ') && f >= 0)
		ft_stringaddc(&str, ' ');
	ft_stringaddd(&str, f, (opt->preci_set) ? opt->preci : 6);
	add_string(out, str.content, str.length, opt);
	free(str.content);
}
