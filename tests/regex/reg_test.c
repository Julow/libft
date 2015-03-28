/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 14:16:18 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/29 00:39:11 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** i = 300000		55 tests: 1450ms
** i = 300000		55 tests: 1370ms
*/

int				main(int argc, char **argv)
{
	int				i;
	t_bool			tmp;

	if (argc > 2)
	{
		printf("%-22s %-25s ", argv[1], argv[2]);
		tmp = ft_rmatch(argv[1], argv[2]);
		i = 300000;
		while (i--)
			if (tmp != ft_rmatch(argv[1], argv[2]))
				return (printf("-1 (Not stable)\n"), 0);
		if (argc > 3 && !!ft_atoi(argv[3]) != tmp)
			printf("%d (FAIL)\n", tmp);
		else
			printf("%d\n", tmp);
	}
	else
		ft_putstr("Need 2 args\n");
	return (0);
}
