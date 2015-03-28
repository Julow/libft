/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 14:16:18 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/28 20:05:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				main(int argc, char **argv)
{
	int				i;
	t_bool			tmp;

	if (argc > 2)
	{
		tmp = ft_rmatch(argv[1], argv[2]);
		i = 100000;
		while (i--)
			if (tmp != ft_rmatch(argv[1], argv[2]))
				return (ft_putstr("-1\n"), 1);
		ft_putstr(ft_rmatch(argv[1], argv[2]) ? "1\n" : "0\n");
	}
	else
		ft_putstr("Need 2 args\n");
	return (0);
}
