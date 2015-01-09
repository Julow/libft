/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 18:13:26 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 11:35:18 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"
#include <stdlib.h>

void			flag_x(t_string *out, t_opt *opt, va_list *ap)
{
	char			*hex;
	t_ulong			x;
	t_string		tmp;

	x = get_unsigned_arg(opt, ap);
	if (x == 0 && opt->preci_set && opt->preci == 0)
	{
		add_string(out, "", 0, opt);
		return ;
	}
	if (opt->format->name == 'x')
		hex = ft_itobase(x, "0123456789abcdef");
	else
		hex = ft_itobase(x, "0123456789ABCDEF");
	ft_stringini(&tmp);
	if (ft_strchr(opt->flags, '#') && x > 0)
		ft_stringadd(&tmp, (opt->format->name == 'x') ? "0x" : "0X");
	ft_stringadd(&tmp, hex);
	pad_preci(&tmp, (ft_strchr(opt->flags, '#') && x > 0) ? 2 : 0, opt);
	add_string(out, tmp.content, tmp.length, opt);
	free(tmp.content);
	free(hex);
}
