/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringrep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 12:34:46 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/17 12:34:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Replace all occurence of the string 'chr' in the t_string 'str'
** by the string 'rep'
** =============
** Return FALSE(0) if the malloc fail, TRUE(1) otherwise
*/
void			ft_stringrep(t_string *str, const char *chr, const char *rep)
{
	int				i;
	int				chr_len;
	int				rep_len;

	chr_len = ft_strlen(chr);
	if (chr_len == 0)
		return ;
	rep_len = (rep == NULL) ? 0 : ft_strlen(rep);
	i = -chr_len;
	while ((i = ft_stringstr(str, chr, i + chr_len)) != -1)
	{
		ft_stringrem(str, i, chr_len);
		if (rep_len > 0)
			ft_stringinsl(str, rep, i, rep_len);
	}
}
