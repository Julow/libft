/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringaddcn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 18:59:32 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 01:55:29 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void			ft_stringaddcn(t_string *str, char c, int n)
{
	char			chars[n];
	int				i;

	if (n < 0)
		return ;
	i = -1;
	while (++i < n)
		chars[i] = c;
	ft_stringaddl(str, chars, n);
}
