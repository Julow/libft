/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_t.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 00:49:25 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/03 01:15:15 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"
#include <termcap.h>

char			*tgetstr(const char *, char **) __attribute__((weak));

int				meta_t(t_printf *pf, t_pfopt *opt, const char *format)
{
	int				i;
	char			buff[5];
	int				len;
	char			*tmp;

	i = 0;
	while (ft_isspace(format[i]))
		i++;
	len = 0;
	while (len < 4 && format[i] && format[i] != '}' && !ft_isspace(format[i]))
		buff[len++] = format[i++];
	buff[len] = '\0';
	margin_before(pf, opt, 0);
	tmp = (tgetstr) ? tgetstr(buff, NULL) : NULL;
	if (tmp != NULL)
		ft_writestr(pf->out, tmp);
	margin_after(pf, opt, 0);
	return (end_meta(format + i) + i);
}
