/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsestr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 19:15:46 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/11 19:19:04 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool			ft_parsestr(t_buff *buff, const char *str)
{
	int				i;

	i = buff->i - 1;
	while (*str == buff->data[++i] && i < buff->length)
		str++;
	if (*str == '\0')
		return ((buff->i = i), TRUE);
	return (FALSE);
}
