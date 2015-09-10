/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rmatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 20:29:07 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/30 01:59:23 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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
