/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memralloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 18:47:46 by juloo             #+#    #+#             */
/*   Updated: 2014/12/27 18:47:46 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_memralloc(void **mem, t_uint len, t_uint newlen)
{
	void			*tmp;

	if (mem == NULL)
		return ;
	tmp = malloc(newlen);
	if (*mem != NULL)
	{
		ft_memcpy(tmp, *mem, MIN(len, newlen));
		ft_bzero(tmp + len, newlen - len);
		free(*mem);
	}
	else
		ft_bzero(tmp, newlen);
	*mem = tmp;
}
