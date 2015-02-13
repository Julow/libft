/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 20:34:30 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/13 00:17:42 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

/*
** -			Initial			libc			using end		using i
** 1			11620			3030			1900			1862
** 10			1169			300				280				267
** 100			142				95				110				75
** 1000			35				48				73				55
** 10000		26				29				51				49
** 100000		32				35				50				51
** 1000000		35				44				89				90
** 10000000		59				94				95				105
** 100000000	77				108				107				112
*/

int				main(int argc, char **argv)
{
	void			*tmp1;
	void			*tmp2;
	t_uint			len;
	t_uint			i;

	len = (argc > 1) ? ft_atoi(argv[1]) : 50;
	i = 1000000000 / len;
	tmp1 = malloc(len);
	tmp2 = malloc(len);
	while (i--)
		ft_memcpy(tmp1, tmp2, len);
	return (0);
}
