/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 12:17:56 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/17 12:17:57 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Split the string 'str' by the string 's'
** =============
** Return a t_array of t_string
*/
t_array			*ft_stringsplit(t_string *str, const char *s)
{
	t_array			*split;
	int				i;
	int				s_len;
	int				tmp;

	split = ft_arraynew();
	s_len = ft_strlen(s);
	i = 0;
	while (s_len > 0 && ft_strnequ(str->content + i, s, s_len)
		&& i < str->length)
		i += s_len;
	while (i < str->length)
	{
		tmp = i;
		while (i < str->length && !ft_strnequ(str->content + i, s, s_len))
			i++;
		if (s_len == 0)
			i++;
		ft_arrayadd(split, ft_stringsub(str, tmp, i - tmp));
		while (s_len > 0 && ft_strnequ(str->content + i, s, s_len)
			&& i < str->length)
			i += s_len;
	}
	return (split);
}
