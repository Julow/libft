/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 23:08:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/11 23:16:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_buff			*ft_out(void)
{
	static t_buff	out = BUFF(NULL, 0, 0);

	if (out.fd < 0)
		out = FBUFF(1);
	return (&out);
}
