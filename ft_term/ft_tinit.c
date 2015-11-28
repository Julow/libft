/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tinit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:48:39 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/27 23:45:23 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_term.h"

t_bool			ft_tinit(t_term *term)
{
	if ((term->name = ft_getenv("TERM", NULL)) == NULL
		|| tgetent(NULL, term->name) <= 0)
		term->name = DEFAULT_TERM;
	if (tgetent(NULL, term->name) <= 0)
		return (false);
	if (tcgetattr(0, &(term->termios)) < 0)
		return (false);
	term->save = term->termios;
	ft_tupdate(term);
	return (true);
}
