/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsebasei.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 19:14:44 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/10 19:19:24 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ulong			ft_parsebasei(t_buff *buff, const char *base)
{
	const t_uint	base_len = ft_strlen(base);
	t_ulong			nb;
	int				tmp;

	nb = 0;
	while ((tmp = ft_strichri(base, BG(buff))) != -1)
		nb = nb * base_len + tmp;
	return (nb);
}
