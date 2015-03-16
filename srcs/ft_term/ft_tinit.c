/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tinit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:48:39 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/16 16:57:53 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

t_bool			ft_tinit(t_term *term)
{
	struct termios	tc;

	if ((term->name = ft_getenv("TERM")) == NULL
		|| tgetent(NULL, term->name) <= 0)
		term->name = DEFAULT_TERM;
	if (tgetent(NULL, term->name) <= 0)
		return (false);
	if (tcgetattr(0, &tc) < 0)
		return (false);
	ft_memcpy(&(term->save), &tc, sizeof(struct termios));
	tc.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL | ICANON);
	tc.c_cc[VMIN] = 1;
	tc.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &tc) < 0)
		return (false);
	term->save_am = (tgetflag("am")) ? true : false;
	TPS("ti"), TPS("vi"), TPS("RA");
	ft_tupdate(term);
	return (true);
}
