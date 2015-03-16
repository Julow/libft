/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writenl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 21:21:40 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/17 00:23:14 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_writenl
** Write '\n' to the buffer
** and flush the buffer
*/
inline void		ft_writenl(t_out *out)
{
	ft_writechar(out, '\n');
	ft_flush(out);
}
