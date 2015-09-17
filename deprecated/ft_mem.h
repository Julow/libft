/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 16:32:19 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/17 16:35:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEM_H
# define FT_MEM_H

# include "libft.h"

void			*ft_memccpy(void *dst, const void *src, int c, t_uint n);

void			*ft_memchr(const void *s, int c, t_uint n);

void			*ft_memalloc(t_uint size);
void			ft_memralloc(void **mem, t_uint len, t_uint newlen);

void			ft_memdel(void **ap);

t_uint			ft_tablen(void **array);

#endif
