/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 21:56:49 by juloo             #+#    #+#             */
/*   Updated: 2015/11/27 23:45:27 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_sub.h"

int				ft_subint(t_sub sub, int *dst)
{
	int			tmp;
	int			i;

	tmp = 0;
	i = -1;
	while (++i < sub.length && IS(sub.str[i], IS_DIGIT))
		tmp = tmp * 10 + sub.str[i] - '0';
	*dst = tmp;
	return (i);
}
