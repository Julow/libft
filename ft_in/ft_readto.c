/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readto.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 20:38:37 by juloo             #+#    #+#             */
/*   Updated: 2016/05/09 16:43:18 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_in.h"

bool			ft_readto_char(t_in *in, char end, t_dstr *dst)
{
	uint32_t		i;

	while (true)
	{
		i = in->buff_i;
		while (i < in->buff_len)
		{
			if (in->buff[i] == end)
				break ;
			i++;
		}
		if (dst != NULL)
			ft_dstradd(dst, SUB(in->buff + in->buff_i, i - in->buff_i));
		in->buff_i = i;
		if (i < in->buff_len)
			return (true);
		if (!ft_in_refresh(in))
			break ;
	}
	return (false);
}

bool			ft_readto_if(t_in *in, t_is end, t_dstr *dst)
{
	uint32_t		i;

	while (true)
	{
		i = in->buff_i;
		while (i < in->buff_len)
		{
			if (IS(in->buff[i], end))
				break ;
			i++;
		}
		if (dst != NULL)
			ft_dstradd(dst, SUB(in->buff + in->buff_i, i - in->buff_i));
		in->buff_i = i;
		if (i < in->buff_len)
			return (true);
		if (!ft_in_refresh(in))
			break ;
	}
	return (false);
}

bool			ft_readto_not(t_in *in, t_is end, t_dstr *dst)
{
	uint32_t		i;

	while (true)
	{
		i = in->buff_i;
		while (i < in->buff_len)
		{
			if (!IS(in->buff[i], end))
				break ;
			i++;
		}
		if (dst != NULL)
			ft_dstradd(dst, SUB(in->buff + in->buff_i, i - in->buff_i));
		in->buff_i = i;
		if (i < in->buff_len)
			return (true);
		if (!ft_in_refresh(in))
			break ;
	}
	return (false);
}

bool			ft_readto_func(t_in *in, bool (*f)(char, void*), void *env,
					t_dstr *dst)
{
	uint32_t		i;

	while (true)
	{
		i = in->buff_i;
		while (i < in->buff_len)
		{
			if (f(in->buff[i], env))
				break ;
			i++;
		}
		if (dst != NULL)
			ft_dstradd(dst, SUB(in->buff + in->buff_i, i - in->buff_i));
		in->buff_i = i;
		if (i < in->buff_len)
			return (true);
		if (!ft_in_refresh(in))
			break ;
	}
	return (false);
}

bool			ft_readto_str(t_in *in, t_sub end, t_dstr *dst)
{
	uint32_t		i;

	if (end.length == 0)
		return (true);
	while (IN_REFRESH(in))
	{
		if (!ft_readto_char(in, end.str[0], dst))
			return (false);
		i = 1;
		while (true)
		{
			if (i >= end.length)
				return (true);
			if (IN_PEEK(in) != end.str[i])
				break ;
			in->buff_i++;
			i++;
		}
		if (dst != NULL)
			ft_dstradd(dst, SUB(end.str, i - 1));
	}
	return (false);
}
