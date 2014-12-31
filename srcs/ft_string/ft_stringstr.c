/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 18:37:44 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/15 18:37:45 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Search the string 'chr' in the string 'str' from the index 'start'
** =============
** Return the index of the first occurence of 'chr' in 'str'
** or -1 if not found
*/
int				ft_stringstr(t_string *str, const char *chr, int start)
{
	int				i;

	while (start < str->length)
	{
		i = 0;
		while (str->content[start + i] == chr[i] && chr[i] != '\0')
			i++;
		if (chr[i] == '\0')
			return (start);
		start++;
	}
	return (-1);
}
