/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argvarg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/18 21:19:33 by juloo             #+#    #+#             */
/*   Updated: 2015/05/26 00:51:20 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_argv.h"

char			*ft_argvarg(t_args *args)
{
	char			*tmp;

	if (args->flags & FTARGS_LONG)
	{
		args->flags &= ~FTARGS_LONG;
		tmp = args->argv[args->c] + args->i + 1;
		args->c++;
		args->i = 1;
		return (tmp);
	}
	while (args->c < args->argc)
	{
		tmp = args->argv[args->c++];
		if (!(tmp[0] == '-' && tmp[1] != '\0'))
			return (tmp);
		tmp += args->i;
		args->i = 1;
		if (*tmp != '\0')
			return (tmp);
	}
	return (NULL);
}
