/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 00:54:43 by juloo             #+#    #+#             */
/*   Updated: 2015/08/10 14:52:26 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_evalexpr.h"
#include <stdio.h>

int				main(int argc, char **argv)
{
	float			result;
	float			tmp;

	if (argc <= 1)
		return (printf("Not enougth argument\n"), 1);
	printf("'%s' = ", argv[1]);
	if (!ft_evalexpr(ft_sub(argv[1], 0, -1), &result))
		return (printf("Invalid expression\n"), 1);
	printf("%f", result);
	if (argc > 2 && ft_subfloat(ft_sub(argv[2], 0, -1), &tmp) > 0)
	{
		if (result == tmp)
			printf(" OK\n");
		else
			return (printf(" ERROR (%f)\n", tmp), 1);
	}
	else
		printf("\n");
	return (0);
}
