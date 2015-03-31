/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 15:48:14 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/31 18:43:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

t_bool			is_separator(char c)
{
	return ((c == ',' || c == ';' || c == ':' || c == '_') ? true : false);
}

void			margin_before(t_printf *pf, t_pfopt *opt, int len)
{
	if (opt->flags & PFLAG_CENTER)
		len = (opt->width - len) / 2;
	else if (opt->flags & PFLAG_RIGHT)
		len = opt->width - pf->printed;
	else if (!(opt->flags & PFLAG_MOINS))
		len = opt->width - len;
	else
		return ;
	if (len <= 0)
		return ;
	pf->printed += len;
	ft_writenchar(pf->out, (opt->flags & PFLAG_ZERO) ? '0' : ' ', len);
}

void			margin_after(t_printf *pf, t_pfopt *opt, int len)
{
	if (opt->flags & PFLAG_CENTER)
		len = (opt->width - len) / 2;
	else if (opt->flags & PFLAG_MOINS)
		len = opt->width - len;
	else
		return ;
	if (len <= 0)
		return ;
	pf->printed += len;
	ft_writenchar(pf->out, ' ', len);
}

int				ft_numlen(t_long num, int base)
{
	int				len;

	len = (num <= 0) ? 1 : 0;
	while (num != 0)
	{
		num /= base;
		len++;
	}
	return (len);
}

int				ft_unumlen(t_ulong num, int base)
{
	int				len;

	len = (num == 0) ? 1 : 0;
	while (num != 0)
	{
		num /= base;
		len++;
	}
	return (len);
}
