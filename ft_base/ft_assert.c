/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/18 16:17:51 by jaguillo          #+#    #+#             */
/*   Updated: 2016/09/08 18:30:57 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"

#include <stdlib.h>
#include <unistd.h>

#define ASSERT_WRITE(STR)	write(2, STR, sizeof(STR) - 1)

bool			ft_assert(char const *err, char const *func)
{
	write(2, err, ft_strlen(err));
	write(2, func, ft_strlen(func));
	ASSERT_WRITE("()\033[39m\n");
	return (false);
}

bool			ft_assert_hard(char const *err, char const *func)
{
	write(2, err, ft_strlen(err));
	write(2, func, ft_strlen(func));
	ASSERT_WRITE("() \033[31mABORT\033[39m\n");
	exit(1);
}
