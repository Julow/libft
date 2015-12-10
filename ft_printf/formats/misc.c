/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 16:03:45 by juloo             #+#    #+#             */
/*   Updated: 2015/12/10 13:07:33 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

void			format_f(t_out *out, t_f_info *info, va_list *ap)
{
	ft_putfloat(out, get_float_arg(ap, info->length));
}

void			format_flush(t_out *out, t_f_info *info, va_list *ap)
{
	ft_flush(out);
	(void)info;
	(void)ap;
}

void			format_endl(t_out *out, t_f_info *info, va_list *ap)
{
	ft_putendl(out);
	(void)info;
	(void)ap;
}
