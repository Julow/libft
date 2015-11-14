/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 14:19:11 by juloo             #+#    #+#             */
/*   Updated: 2015/11/13 21:32:21 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "out_internal.h"

void			ft_write(t_out *out, char const *data, int32_t len)
{
	if (len < 0)
		len = ft_strlen(data) + len + 1;
	ft_write_sub(out, SUB(data, len));
}
