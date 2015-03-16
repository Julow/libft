/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termrestore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:50:28 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/16 16:50:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void			ft_trestore(t_term *term)
{
	if (term->save_am)
		TPS("SA");
	TPS("cl"), TPS("te"), TPS("ve"), FL;
	tcsetattr(0, TCSADRAIN, &(term->save));
}
