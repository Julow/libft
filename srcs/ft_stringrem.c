/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringrem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 12:27:45 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/17 12:27:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Remove 'len' char in the string 'str' from 'index'
*/
void			ft_stringrem(t_string *str, int index, int len)
{
	int				i;
	int				tmp;

	i = index - 1;
	while (++i + len < str->length)
		str->content[i] = str->content[i + len];
	tmp = i;
	i--;
	while (++i < str->length)
		str->content[i] = '\0';
	str->length -= i - tmp;
}
