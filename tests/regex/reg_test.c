/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 14:16:18 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/27 15:38:53 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				main(int argc, char **argv)
{
	if (argc > 2)
		ft_putstr(ft_rmatch(argv[1], argv[2]) ? "1\n" : "0\n");
	else
		ft_putstr("Need 2 args\n");
	return (0);
}
