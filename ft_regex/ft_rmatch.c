/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rmatch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 10:58:38 by juloo             #+#    #+#             */
/*   Updated: 2015/12/26 18:16:32 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_internal.h"

// uint32_t		exec_reg_str(t_rmatch const *rmatch, t_reg_str const *reg,
// 					uint32_t offset);
// uint32_t		exec_reg_char(t_rmatch const *rmatch, t_reg_char const *reg,
// 					uint32_t offset);
// uint32_t		exec_reg_is(t_rmatch const *rmatch, t_reg_is const *reg,
// 					uint32_t offset);
// uint32_t		exec_reg_set(t_rmatch const *rmatch, t_reg_set const *reg,
// 					uint32_t offset);
// uint32_t		exec_reg_group(t_rmatch const *rmatch, t_reg_group const *reg,
// 					uint32_t offset);

// uint32_t		exec_reg_str(t_rmatch const *rmatch, t_reg_str const *reg,
// 					uint32_t offset)
// {
// 	char const		*str;
// 	uint32_t		i;

// 	if (rmatch->str_len - offset < reg->str.length)
// 		return (REG_FAIL);
// 	str = rmatch->str + offset;
// 	i = 0;
// 	while (i < reg->str.length)
// 	{
// 		if (str[i] != reg->str.str[i])
// 			return (REG_FAIL);
// 		i++;
// 	}
// 	return (offset + i);
// }

// uint32_t		exec_reg_char(t_rmatch const *rmatch, t_reg_char const *reg,
// 					uint32_t offset)
// {
// 	if (rmatch->str_len <= offset && rmatch->str[offset] == reg->c)
// 		return (offset + 1);
// 	return (REG_FAIL);
// }

// uint32_t		exec_reg_is(t_rmatch const *rmatch, t_reg_is const *reg,
// 					uint32_t offset)
// {
// 	if (rmatch->str_len <= offset && IS(rmatch->str[offset], reg->is))
// 		return (offset + 1);
// 	return (REG_FAIL);
// }

// uint32_t		exec_reg_set(t_rmatch const *rmatch, t_reg_set const *reg,
// 					uint32_t offset)
// {
// 	if (rmatch->str_len <= offset && rmatch->str[offset] > 0
// 		&& BITARRAY_GET(reg->set, rmatch->str[offset]))
// 		return (offset + 1);
// 	return (REG_FAIL);
// }

// uint32_t		exec_reg_group(t_rmatch const *rmatch, t_reg_group const *reg,
// 					uint32_t offset)
// {
// 	return (exec_reg(rmatch, reg->group, offset));
// }

// static uint32_t	(*g_reg_exec[])() = {
// 	[REG_T_STR] = &exec_reg_str,
// 	[REG_T_CHAR] = &exec_reg_char,
// 	[REG_T_IS] = &exec_reg_is,
// 	[REG_T_SET] = &exec_reg_set,
// 	[REG_T_GROUP] = &exec_reg_group,
// };

// uint32_t		exec_reg(t_rmatch const *rmatch, t_reg const *reg,
// 					uint32_t offset)
// {
// 	uint32_t		n;
// 	uint32_t		tmp;

// 	n = 0;
// 	while (n < reg->max)
// 	{
// 		tmp = g_reg_exec[reg->type](rmatch, reg, offset);
// 		if (tmp == REG_FAIL)
// 			break ;
// 		n++;
// 		offset = tmp;
// 	}
// 	if (n >= reg->min)
// 	{
// 		reg = reg->next;
// 		while (reg != NULL)
// 		{
// 			tmp = exec_reg(rmatch, reg, offset);
// 			if (tmp != REG_FAIL)
// 			{
// 				offset = tmp;
// 				break ;
// 			}
// 			reg = reg->or_next;
// 		}
// 		return (offset);
// 	}
// 	return (REG_FAIL);
// }
