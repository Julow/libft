/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 19:38:49 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/17 12:30:42 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool			ft_stringset(t_string *str, char *set, int index)
{
	return (ft_stringsetl(str, set, index, ft_strlen(set)));
}
