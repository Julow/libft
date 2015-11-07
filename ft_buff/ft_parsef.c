/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsef.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 15:28:58 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/17 17:02:01 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buff.h"

t_bool			ft_parsef(t_buff *buff, t_bool (*f)(int))
{
	if (!BIF(buff, f))
		return (false);
	while (f(BG(buff)))
		buff->i++;
	return (true);
}