/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rmatch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 10:58:38 by juloo             #+#    #+#             */
/*   Updated: 2015/12/31 22:27:23 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

uint32_t		ft_rmatch(t_sub str, t_regex const *regex, t_sub *captures)
{
	t_rmatch		rmatch;

	rmatch = (t_rmatch){str.str, str.length, captures};
	return (exec_reg(&rmatch, regex->reg, 0));
}
