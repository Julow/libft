/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringsplitc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 12:20:36 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/17 12:20:37 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Split the string 'str' by the char 'c'
** =============
** Return a t_array of t_string
*/
t_array			*ft_stringsplitc(t_string *str, char c)
{
	t_array			*split;
	int				i;
	int				tmp;

	split = ft_arraynew();
	i = 0;
	while (str->content[i] == c && i < str->length)
		i++;
	while (i < str->length)
	{
		tmp = i;
		while (i < str->length && str->content[i] != c)
			i++;
		ft_arrayadd(split, ft_stringsub(str, tmp, i - tmp));
		while (str->content[i] == c && i < str->length)
			i++;
	}
	return (split);
}
