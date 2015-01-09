/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 18:09:04 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 11:35:20 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

static int		add_ulong(char *str, int i, t_ulong nb, t_opt *opt)
{
	const int		len = i;

	while (i > 0 && nb != 0)
	{
		str[i--] = '0' + (nb % 10);
		if (((len - i + 1) % 4) == 0 && HASF('\''))
			str[i--] = ' ';
		nb /= 10;
	}
	return (i);
}

void			flag_u(t_string *out, t_opt *opt, va_list *ap)
{
	const int		len = MAX(LONG_BUFF, MAX(opt->width, opt->preci));
	char			str[len];
	int				i;
	int				pad;
	t_ulong			nb;

	nb = (opt->format->name != 'U') ? get_unsigned_arg(opt, ap) :
		(t_ulong)(va_arg(*ap, unsigned long int));
	i = len - 1;
	if (nb == 0 && (!opt->preci_set || opt->preci != 0))
		str[i--] = '0';
	else
		i = add_ulong(str, i, nb, opt);
	pad = ((opt->preci_set) ? MIN(opt->width, opt->preci) : opt->width) + 1;
	if (HASF('0'))
		while ((len - i) < pad)
			str[i--] = '0';
	if (opt->preci_set)
		while ((len - i - 1) < opt->preci)
			str[i--] = '0';
	add_string(out, str + 1 + i, len - 1 - i, opt);
}
