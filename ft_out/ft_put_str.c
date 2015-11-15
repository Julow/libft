/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 14:19:11 by juloo             #+#    #+#             */
/*   Updated: 2015/11/15 20:24:17 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "out_internal.h"

void			ft_put_str(t_out *out, char const *data, int32_t len)
{
	if (len < 0)
		len = ft_strlen(data) + len + 1;
	out_before(out, len);
	out_writestr(out, data, len);
	out_after(out, len);
}
