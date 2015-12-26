/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regs_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 18:11:27 by juloo             #+#    #+#             */
/*   Updated: 2015/12/26 18:15:15 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

t_reg			*create_reg_str(t_sub str)
{
	t_reg_str *const	r = ft_emalloc(sizeof(t_reg_str) + str.length);

	ft_memcpy(ENDOF(r), str.str, str.length);
	r->reg.type = REG_T_STR;
	r->str = SUB(ENDOF(r), str.length);
	return (V(r));
}
