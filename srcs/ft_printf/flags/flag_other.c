/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_other.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 18:52:20 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/31 19:00:49 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

void			flag_other(t_printf *pf, t_pfopt *opt, char c)
{
	if (c == '\0')
		return ;
	margin_before(pf, opt, 1);
	ft_writechar(pf->out, c);
	pf->printed += 1;
	margin_after(pf, opt, 1);
}
