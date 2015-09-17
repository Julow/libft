/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:35:29 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/12 22:48:04 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline char		*ft_strcpy(char *dst, const char *src)
{
	ft_memcpy(dst, src, ft_strlen(src) + 1);
	return (dst);
}
