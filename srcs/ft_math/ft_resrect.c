/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resrect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 16:09:23 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/12 22:24:33 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline void		ft_resrect(t_rect *rect, t_rect bounds)
{
	if (rect->width < 0)
	{
		rect->x += rect->width;
		rect->x = 0;
	}
	if (rect->height < 0)
	{
		rect->y += rect->height;
		rect->y = 0;
	}
	if (rect->x < bounds.x)
	{
		rect->width -= bounds.x - rect->x;
		rect->x = bounds.x;
	}
	if (rect->y < bounds.y)
	{
		rect->height -= bounds.y - rect->y;
		rect->y = bounds.y;
	}
	if ((rect->x + rect->width) > (bounds.x + bounds.width))
		rect->width = bounds.width - rect->x;
	if ((rect->y + rect->height) > (bounds.y + bounds.height))
		rect->height = bounds.height - rect->y;
}
