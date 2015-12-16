/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tupdate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:49:36 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/16 18:12:13 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/term.h"
#include <sys/ioctl.h>

void			ft_tupdate(t_term *term)
{
	struct winsize	win;

	ioctl(2, TIOCGWINSZ, &win);
	term->width = MAX(win.ws_col, 1);
	term->height = MAX(win.ws_row, 1);
}
