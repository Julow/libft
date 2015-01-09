/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 12:53:30 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 11:35:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

void			flag_percent(t_string *out, t_opt *opt, va_list *ap)
{
	char			c;

	c = '%';
	add_string(out, &c, 1, opt);
	(void)ap;
}
