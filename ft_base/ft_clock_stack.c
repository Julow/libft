/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clock_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 18:43:49 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/09 17:39:33 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"

static uint64_t	g_clock_stack[256] = {0};
static uint32_t	g_clock_stack_index = 0;

uint64_t		ft_cstart(void)
{
	uint64_t const		t = ft_clock(0);

	g_clock_stack_index++;
	if (g_clock_stack_index < ARRAY_LEN(g_clock_stack))
		g_clock_stack[g_clock_stack_index] = t;
	return (t);
}

uint64_t		ft_cend(void)
{
	uint64_t			t;

	if (g_clock_stack_index < ARRAY_LEN(g_clock_stack))
		t = ft_clock(g_clock_stack[g_clock_stack_index]);
	else
		t = 0;
	g_clock_stack_index--;
	return (t);
}
