/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringputfd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 12:24:02 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 01:55:25 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <unistd.h>

/*
** Write the string 'str' to the file 'fd'
** =============
** Return the return value of the 'write' function
*/
int				ft_stringputfd(t_string *str, int const fd)
{
	return (write(fd, str->content, str->length));
}
