/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsebase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 21:55:25 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/11 00:02:53 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ulong			ft_parsebase(t_buff *buff, const char *base)
{
	const t_uint	base_len = ft_strlen(base);
	t_ulong			nb;
	int				tmp;

	nb = 0;
	while ((tmp = ft_strchri(base, BG(buff))) != -1)
	{
		nb = nb * base_len + tmp;
		buff->i++;
	}
	return (nb);
}
