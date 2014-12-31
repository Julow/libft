/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayapp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 16:08:33 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/15 16:08:34 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_arrayapp(t_array *array, const t_array *app)
{
	int				i;
	int				app_len;

	app_len = app->length;
	array->length += app_len;
	if (!ft_arrayext(array, app->length))
		return ;
	i = -1;
	while (++i < app_len)
		array->data[array->length - app_len + i] = app->data[i];
}
