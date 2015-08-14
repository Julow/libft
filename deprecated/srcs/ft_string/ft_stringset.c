/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 19:38:49 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 01:55:24 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void			ft_stringset(t_string *str, const char *set, int index)
{
	ft_stringsetl(str, set, index, ft_strlen(set));
}
