/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rdestroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 18:14:54 by juloo             #+#    #+#             */
/*   Updated: 2015/12/31 20:20:38 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"
#include <stdlib.h>

void			destroy_reg(t_reg *reg)
{
	t_reg *const	tmp = reg;

	if (reg == NULL)
		return ;
	destroy_reg(reg->next);
	while ((reg = reg->or_next) != NULL)
		destroy_reg(reg);
	free(tmp);
}

void			ft_rdestroy(t_regex *regex)
{
	destroy_reg(regex->reg);
}
