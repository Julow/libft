/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 12:53:30 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/31 16:50:15 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

void			flag_percent(t_printf *pf, t_pfopt *opt)
{
	margin_before(pf, opt, 1);
	pf->printed += 1;
	ft_writechar(pf->out, '%');
	margin_after(pf, opt, 1);
}
