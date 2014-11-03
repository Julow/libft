/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:26:28 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/03 11:26:35 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

size_t			ft_strlen(char *str)
{
	size_t			len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
