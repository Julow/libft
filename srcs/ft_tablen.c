/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 17:24:23 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/14 17:24:25 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_uint			ft_tablen(void **array)
{
	void			**tmp;

	tmp = array;
	while (*tmp != NULL)
		tmp++;
	return (tmp - array);
}
