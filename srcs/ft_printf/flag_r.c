/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 17:53:49 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 11:35:24 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"
#include <stdlib.h>

static void		stringaddcr(t_string *str, char r)
{
	if (!ft_isprint(r))
	{
		ft_stringaddc(str, '\\');
		ft_stringaddi(str, (int)r);
	}
	else
		ft_stringaddc(str, r);
}

void			flag_r(t_string *out, t_opt *opt, va_list *ap)
{
	char			*r;
	t_string		str;
	int				i;

	r = va_arg(*ap, char*);
	if (r == NULL)
	{
		add_string(out, "(null)", 6, opt);
		return ;
	}
	ft_stringini(&str);
	ft_stringext(&str, ft_strlen(r));
	i = -1;
	while (r[++i] != '\0')
		stringaddcr(&str, r[i]);
	i = str.length;
	if (opt->preci_set && i > opt->preci)
		i = opt->preci;
	if (opt->preci_set && opt->preci < 0)
		add_nchar(out, ' ', ABS(i), opt);
	else
		add_string(out, str.content, i, opt);
	free(str.content);
}
