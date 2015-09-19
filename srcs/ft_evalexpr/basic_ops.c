/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 12:19:33 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/19 12:19:55 by jaguillo         ###   ########.fr       */
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
