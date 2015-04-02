/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 01:31:36 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/03 01:44:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

static int		strmaxlen(const char *str, int max)
{
	int				len;

	len = -1;
	while (++len < max)
	{
		if (str[len] == '\0')
			break ;
	}
	return (len);
}

static int		write_r(t_out *out, const char *str, int len)
{
	int				printed;
	int				i;
	char			tmp;

	i = -1;
	printed = len;
	while (++i < len)
	{
		if (!ft_isprint(str[i]))
		{
			ft_writechar(out, '\\');
			printed++;
			if ((tmp = ft_escape(str[i])) != str[i])
				ft_writechar(out, tmp);
			else
			{
				ft_writechar(out, 'x');
				if (((t_byte)str[i]) < 16)
					ft_writechar(out, '0');
				ft_writebase(out, (t_byte)(str[i]), BASE_16);
				printed += 2;
			}
		}
		else
			ft_writechar(out, str[i]);
	}
	return (printed);
}

void			flag_r(t_printf *pf, t_pfopt *opt)
{
	char			*str;
	int				length;

	str = va_arg(*(pf->ap), char*);
	if (str == NULL)
		str = "(null)";
	if (opt->flags & PFLAG_PRECI)
		length = strmaxlen(str, opt->preci);
	else
		length = ft_strlen(str);
	margin_before(pf, opt, length);
	pf->printed += write_r(pf->out, str, length);
	margin_after(pf, opt, length);
}
