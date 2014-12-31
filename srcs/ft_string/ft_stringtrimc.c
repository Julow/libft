/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs/ft_stringtrimc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 15:28:48 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/07 15:28:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_stringtrimc(t_string *str, const char *trim)
{
	int				i;

	i = str->length - 1;
	while (i >= 0 && ft_strchri(trim, str->content[i]) != -1)
		i--;
	i++;
	ft_stringrem(str, i, str->length - i);
	i = 0;
	while (ft_strchri(trim, str->content[i]) != -1)
		i++;
	ft_stringrem(str, 0, i);
}
