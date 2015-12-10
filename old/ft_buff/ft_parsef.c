/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsef.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 15:28:58 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:14:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_buff.h"

bool			ft_parsef(t_buff *buff, bool (*f)(int))
{
	if (!BIF(buff, f))
		return (false);
	while (f(BG(buff)))
		buff->i++;
	return (true);
}
