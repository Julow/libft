/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_emalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 22:33:49 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/21 12:16:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

/*
** Try to malloc 'size' bytes
** If malloc fail, put EMAL_ERROR on stderr and exit with code EMAL_EXIT
*/

inline void		*ft_emalloc(t_uint size)
{
	void			*mem;

	if ((mem = malloc(size)) == NULL)
	{
		write(2, EMAL_ERROR, ft_strlen(EMAL_ERROR));
		exit(EMAL_EXIT);
	}
	return (mem);
}
