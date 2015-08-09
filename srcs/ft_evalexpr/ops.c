/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 00:31:05 by juloo             #+#    #+#             */
/*   Updated: 2015/08/10 00:32:08 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_evalexpr.h"

float			op_plus(float a, float b)
{
	return (a + b);
}

float			op_moins(float a, float b)
{
	return (a - b);
}

float			op_mult(float a, float b)
{
	return (a * b);
}

float			op_div(float a, float b)
{
	return (a / b);
}
