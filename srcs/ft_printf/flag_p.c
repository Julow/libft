/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 16:06:18 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 11:35:30 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"
#include <stdlib.h>

void			flag_p(t_string *out, t_opt *opt, va_list *ap)
{
	char			*hex;
	t_string		tmp;

	ft_stringini(&tmp);
	ft_stringins(&tmp, "0x", 0);
	if (!opt->preci_set || opt->preci != 0)
	{
		hex = ft_itobase((t_ulong)(va_arg(*ap, void*)), "0123456789abcdef");
		ft_stringadd(&tmp, hex);
		pad_preci(&tmp, 2, opt);
		free(hex);
	}
	add_string(out, tmp.content, tmp.length, opt);
	free(tmp.content);
}
