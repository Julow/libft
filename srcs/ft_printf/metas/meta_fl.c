/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_fl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 00:23:58 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/03 00:25:25 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

void			meta_fl(t_printf *pf, t_pfopt *opt)
{
	margin_before(pf, opt, 0);
	margin_after(pf, opt, 0);
	ft_flush(pf->out);
}
