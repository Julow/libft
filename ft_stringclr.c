/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringclr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 12:26:37 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/17 12:26:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_stringclr(t_string *str)
{
	int				i;

	i = -1;
	while (++i < str->length)
		str->content[i] = '\0';
	str->length = 0;
}
