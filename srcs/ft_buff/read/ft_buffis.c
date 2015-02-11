/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 10:26:53 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/01 10:27:06 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_bool	ft_buffis(t_buff *buff, char c)
{
	if (BG(buff) == c)
		return (buff->i++, true);
	return (false);
}
