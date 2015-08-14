/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringadd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 18:04:05 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 01:55:30 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

inline void		ft_stringadd(t_string *str, const char *add)
{
	ft_stringaddl(str, add, ft_strlen(add));
}
