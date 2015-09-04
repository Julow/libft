/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tupdate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:49:36 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/16 16:53:23 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"
#include <sys/ioctl.h>

void			ft_tupdate(t_term *term)
{
	struct winsize	win;

	ioctl(2, TIOCGWINSZ, &win);
	term->width = win.ws_col;
	term->height = win.ws_row;
}
