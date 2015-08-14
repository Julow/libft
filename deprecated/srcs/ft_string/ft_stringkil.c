/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringkil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 18:32:51 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 01:55:26 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

void			ft_stringkil(void *str)
{
	if (str != NULL)
	{
		if (((t_string*)str)->content != NULL)
			free(((t_string*)str)->content);
		free(str);
	}
}
