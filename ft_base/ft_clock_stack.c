/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clock_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 18:43:49 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/15 18:45:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"

static uint64_t	clock_stack[256] = {};
static uint32_t	clock_stack_index = 0;

uint64_t		ft_cstart(void)
{
	uint64_t const		t = ft_clock(0);

	clock_stack_index++;
	if (clock_stack_index < ARRAY_LEN(clock_stack))
		clock_stack[clock_stack_index] = t;
	return (t);
}

uint64_t		ft_cend(void)
{
	uint64_t			t;

	if (clock_stack_index < ARRAY_LEN(clock_stack))
		t = ft_clock(clock_stack[clock_stack_index]);
	else
		t = 0;
	clock_stack_index--;
	return (t);
}
