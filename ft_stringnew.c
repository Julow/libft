/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 16:58:45 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/15 17:15:30 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_string		*ft_stringnew(void)
{
	t_string		*str;

	str = MAL1(t_string);
	if (str != NULL)
	{
		str->content = MAL(char, 1);
		if (str->content != NULL)
			str->content[0] = '\0';
		str->length = 0;
		str->alloc_length = (str->content == NULL) ? 0 : 1;
	}
	return (str);
}
