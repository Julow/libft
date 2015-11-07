/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 12:11:53 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/21 12:13:12 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_var.h"

void			*ft_varget(t_var_strct *v, int size)
{
	void *const		tmp = v->data + v->curr;

	v->curr += (size - ((v->curr + size) % size)) % size + size;
	return (tmp);
}
