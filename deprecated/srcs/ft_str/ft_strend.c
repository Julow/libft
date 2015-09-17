/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 01:06:56 by juloo             #+#    #+#             */
/*   Updated: 2015/05/26 01:07:03 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool			ft_strend(const char *str, const char *end)
{
	const char		*start_str = str;
	const char		*start_end = end;

	str += ft_strlen(str);
	end += ft_strlen(end);
	while (str > start_str && end > start_end)
		if (*(--str) != *(--end))
			return (false);
	return (true);
}
