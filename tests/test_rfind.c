/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 20:37:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/30 13:09:20 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int				main(int argc, char **argv)
{
	t_sub			sub;

	if (argc > 2)
	{
		if (ft_rfind(&sub, argv[1], argv[2]))
		{
			printf("'%.*s'  l: %d ; o: %ld\n", sub.length, sub.str,
				sub.length, sub.str - argv[1]);
			while (ft_rnext(&sub, argv[2]))
				printf("- '%.*s'  l: %d ; o: %ld\n", sub.length, sub.str,
					sub.length, sub.str - argv[1]);
		}
		else
			printf("NULL\n");
	}
	return (0);
}
