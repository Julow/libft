/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tmakeraw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 01:55:14 by juloo             #+#    #+#             */
/*   Updated: 2015/11/27 23:45:25 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_term.h"

void			ft_tmakeraw(t_term *term)
{
	term->termios.c_iflag &= ~(IGNBRK | BRKINT | PARMRK
		| INLCR | IGNCR | ICRNL | ISTRIP | IXON);
	term->termios.c_oflag &= ~(OPOST);
	term->termios.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
	term->termios.c_cflag &= ~(CSIZE | PARENB);
	term->termios.c_cflag |= CS8;
	term->termios.c_cc[VMIN] = 1;
	term->termios.c_cc[VTIME] = 0;
}
