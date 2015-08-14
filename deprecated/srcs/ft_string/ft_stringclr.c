/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringclr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 12:26:37 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 01:55:27 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void			ft_stringclr(t_string *str)
{
	ft_bzero(str->content, sizeof(char) * str->length);
	str->length = 0;
}
