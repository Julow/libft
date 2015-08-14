/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringinsc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 18:45:05 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 01:55:26 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

inline void		ft_stringinsc(t_string *str, char c, int index)
{
	ft_stringinsl(str, &c, index, 1);
}
