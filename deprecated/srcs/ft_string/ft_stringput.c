/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringput.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 12:21:27 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/14 01:55:25 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <unistd.h>

/*
** Write the string 'str' to stdout
** =============
** Return the return value of the 'write' function
*/
int				ft_stringput(t_string *str)
{
	return (write(1, str->content, str->length));
}
