/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 17:29:19 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/15 17:29:20 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_bool			ft_stringext(t_string *str, int need)
{
	char			*tmp;
	int				i;

	need += str->length;
	if (need + 1 < str->alloc_length)
		return (TRUE);
	i = str->alloc_length - 1;
	while (need >= i)
		i += 16;
	tmp = MAL(char, i);
	if (tmp == NULL)
		return (FALSE);
	str->alloc_length = i;
	i = -1;
	if (str->content != NULL)
	{
		while (++i < str->length)
			tmp[i] = str->content[i];
		i--;
		free(str->content);
	}
	while (++i < str->alloc_length)
		tmp[i] = '\0';
	str->content = tmp;
	return (TRUE);
}
