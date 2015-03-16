/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:47:59 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/16 16:50:57 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"
#include <unistd.h>

int				ft_getchr(void)
{
	int				chr;

	chr = 0;
	if (read(0, &chr, sizeof(int)) <= 0)
		return (EOF);
	return (chr);
}
