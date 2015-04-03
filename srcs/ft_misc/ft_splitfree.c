/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitfree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 15:49:30 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/03 15:49:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_splitfree(char **split)
{
	int				i;

	if (split == NULL)
		return ;
	i = -1;
	while (split[++i] != NULL)
		free(split[i]);
	free(split);
}
