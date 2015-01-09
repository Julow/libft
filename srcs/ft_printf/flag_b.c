/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 17:45:15 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 11:35:51 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"
#include <stdlib.h>

void			flag_b(t_string *out, t_opt *opt, va_list *ap)
{
	t_long			b;
	char			*binary;
	t_string		tmp;

	b = get_unsigned_arg(opt, ap);
	binary = ft_itobase(b, "01");
	if (ft_strchr(opt->flags, '#') && b > 0)
	{
		ft_stringini(&tmp);
		ft_stringadd(&tmp, "0");
		ft_stringaddc(&tmp, opt->format->name);
		ft_stringadd(&tmp, binary);
		add_string(out, tmp.content, tmp.length, opt);
		free(tmp.content);
	}
	else
		add_string(out, binary, ft_strlen(binary), opt);
	free(binary);
}
