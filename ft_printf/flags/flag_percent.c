/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 12:53:30 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/07 15:13:47 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

void			flag_percent(t_printf *pf, t_pfopt *opt)
{
	margin_before(pf, opt, 1);
	pf->printed += 1;
	ft_writechar(pf->out, '%');
	margin_after(pf, opt, 1);
}
