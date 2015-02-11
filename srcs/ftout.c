/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftout.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 19:07:23 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/11 19:07:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftout.h"

t_ftout			g_ftout = {
	1,
	{ 0 },
	0
};

void			ft_out_add(const char *str, t_uint len)
{
	t_uint			free_buff;

	while (1)
	{
		free_buff = FTOUT_BUFF - g_ftout.buff_len;
		if (len <= free_buff)
			break ;
		ft_out_add(str, free_buff);
		ft_out_flush();
		str += free_buff;
		len -= free_buff;
	}
	ft_memcpy(g_ftout.buff, str, len);
}

void			ft_out_add_c(char c)
{
	if (g_ftout.buff_len >= FTOUT_BUFF)
		ft_out_flush();
	g_ftout.buff[g_ftout.buff_len++] = c;
}

void			ft_out_flush()
{
	if (g_ftout.buff_len > 0)
	{
		write(g_ftout.buff, g_ftout.buff_len);
		g_ftout.buff_len = 0;
	}
}

t_ftout			*ft_out_i(int n)
{
	ft_out_l((t_long)n);
	return (&g_ftout);
}

t_ftout			*ft_out_u(t_uint n)
{
	ft_out_ul((t_ulong)n);
	return (&g_ftout);
}

t_ftout			*ft_out_l(t_long n)
{
	char			nb[PUTLONG_BUFF];
	t_uint			i;

	i = PUTLONG_BUFF;
	nb[0] = (n < 0) ? '-' : '+';
	if (n <= 0)
	{
		nb[--i] = '0' - (n % 10);
		n /= -10;
	}
	while (n != 0)
	{
		nb[--i] = '0' + (n % 10);
		n /= 10;
	}
	if (nb[0] == '-')
		nb[--i] = '-';
	ft_out_add(nb + i, PUTLONG_BUFF - i);
	return (&g_ftout);
}

t_ftout			*ft_out_ul(t_ulong n)
{
	char			nb[PUTLONG_BUFF];
	t_uint			i;

	i = PUTLONG_BUFF;
	while (n != 0)
	{
		nb[--i] = '0' + (n % 10);
		n /= 10;
	}
	ft_out_add(nb + i, PUTLONG_BUFF - i);
	return (&g_ftout);
}

t_ftout			*ft_out_c(char c)
{
	ft_out_add_c(c);
	return (&g_ftout);
}

t_ftout			*ft_out_cn(char c, t_uint n)
{
	while (n--)
		ft_out_add_c(c);
	return (&g_ftout);
}

t_ftout			*ft_out_sl(const char *str, t_uint len)
{
	ft_out_add(str, len);
	return (&g_ftout);
}

t_ftout			*ft_out_s(const char *str)
{
	ft_out_add(str, ft_strlen(str));
	return (&g_ftout);
}

t_ftout			*ft_out_n()
{
	ft_out_add_c('\n');
	ft_out_flush();
	return (&g_ftout);
}

t_ftout			*ft_out_z()
{
	ft_out_add_c('\0');
	ft_out_flush();
	return (&g_ftout);
}

t_ftout			*ft_out_f()
{
	ft_out_flush();
	return (&g_ftout);
}
