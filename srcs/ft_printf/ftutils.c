/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftutils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 17:08:10 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/12 23:25:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

void			ft_stringaddupper(t_string *str, const char *add, int len)
{
	ft_stringext(str, len);
	len += str->length;
	while (str->length < len)
	{
		str->content[str->length++] = (*add >= 'a' && *add <= 'z')
			? *add - 32 : *add;
		add++;
	}
}

void			ft_stringaddlower(t_string *str, const char *add, int len)
{
	ft_stringext(str, len);
	len += str->length;
	while (str->length < len)
	{
		str->content[str->length++] = (*add >= 'A' && *add <= 'Z')
			? *add + 32 : *add;
		add++;
	}
}

int				ft_atoin(const char *str, int len)
{
	int				nb;
	int				sign;

	sign = 1;
	nb = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
		len--;
	}
	else if (*str == '+')
	{
		len--;
		str++;
	}
	while (*str >= '0' && *str <= '9' && len-- > 0)
		nb = nb * 10 + (*(str++) - '0');
	return (nb * sign);
}
