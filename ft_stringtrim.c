/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringtrim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 12:25:35 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/17 12:25:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Trim the string 'str'
** (Remove whitespaces before and after the string)
*/
void			ft_stringtrim(t_string *str)
{
	int				i;

	i = str->length - 1;
	while (i >= 0 && ft_isspace(str->content[i]))
		i--;
	i++;
	ft_stringrem(str, i, str->length - i);
	i = 0;
	while (ft_isspace(str->content[i]))
		i++;
	ft_stringrem(str, 0, i);
}
