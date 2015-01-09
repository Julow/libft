/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:54:49 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 11:35:32 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"
#include <stdlib.h>

void			flag_o(t_string *out, t_opt *opt, va_list *ap)
{
	t_ulong			o;
	char			*octal;
	t_string		tmp;

	if (opt->format->name == 'O')
		o = (t_long)(va_arg(*ap, unsigned long int));
	else
		o = get_unsigned_arg(opt, ap);
	if (o == 0 && opt->preci_set && opt->preci == 0)
	{
		add_string(out, (ft_strchr(opt->flags, '#') != NULL) ? "0" : "",
			(ft_strchr(opt->flags, '#')) ? 1 : 0, opt);
		return ;
	}
	octal = ft_itobase(o, "01234567");
	ft_stringini(&tmp);
	if (ft_strchr(opt->flags, '#') && o > 0)
		ft_stringaddc(&tmp, '0');
	ft_stringadd(&tmp, octal);
	pad_preci(&tmp, (ft_strchr(opt->flags, '#') && o > 0) ? 1 : 0, opt);
	add_string(out, tmp.content, tmp.length, opt);
	free(tmp.content);
	free(octal);
}
