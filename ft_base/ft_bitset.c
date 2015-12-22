/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 18:13:32 by juloo             #+#    #+#             */
/*   Updated: 2015/12/23 00:10:43 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"

void			ft_bitset(t_bits *array, uint32_t bit, uint32_t n)
{
	t_bits			tmp;

	array += BITARRAY_CHUNK(bit);
	bit = BITARRAY_BIT_INDEX(bit);
	tmp = BITARRAY(bit) * BSIZEOF(t_bits);
	if (tmp > bit)
	{
		tmp = MIN(n, tmp - bit);
		*array |= BIT_RANGE(bit, tmp);
		n -= tmp;
		array++;
	}
	while (n >= BSIZEOF(t_bits))
	{
		*array = (t_bits)-1;
		array++;
		n -= BSIZEOF(t_bits);
	}
	if (n > 0)
		*array |= BIT_RANGE(0, n);
}

void			ft_bitclear(t_bits *array, uint32_t bit, uint32_t n)
{
	t_bits			tmp;

	array += BITARRAY_CHUNK(bit);
	bit = BITARRAY_BIT_INDEX(bit);
	tmp = BITARRAY(bit) * BSIZEOF(t_bits);
	if (tmp > bit)
	{
		tmp = MIN(n, tmp - bit);
		*array &= ~BIT_RANGE(bit, tmp);
		n -= tmp;
		array++;
	}
	while (n >= BSIZEOF(t_bits))
	{
		*array = 0;
		array++;
		n -= BSIZEOF(t_bits);
	}
	if (n > 0)
		*array &= ~BIT_RANGE(0, n);
}
