/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_emalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 22:33:49 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:17:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"
#include <stdlib.h>
#include <unistd.h>

/*
** Try to malloc 'size' bytes
** If malloc fail, put EMAL_ERROR on stderr and exit with code EMAL_EXIT
*/

inline void		*ft_emalloc(uint32_t size)
{
	void			*mem;

	if ((mem = malloc(size)) == NULL)
	{
		write(2, EMAL_ERROR, ft_strlen(EMAL_ERROR));
		exit(EMAL_EXIT);
	}
	return (mem);
}
