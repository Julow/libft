/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringkil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 18:32:51 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/15 18:32:52 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
