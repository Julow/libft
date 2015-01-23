/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_emalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 22:33:49 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/23 14:13:00 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Try to malloc 'size' bytes
** If malloc fail, put EMAL_ERROR on stderr and exit with code EMAL_EXIT
*/
inline void		*ft_emalloc(t_uint size)
{
	void			*mem;

	if ((mem = malloc(size)) == NULL)
	{
		ft_putstr_fd(EMAL_ERROR, 2);
		exit(EMAL_EXIT);
	}
	return (mem);
}
