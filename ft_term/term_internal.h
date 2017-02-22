/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 12:12:55 by jaguillo          #+#    #+#             */
/*   Updated: 2017/02/22 15:45:53 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_INTERNAL_H
# define TERM_INTERNAL_H

# include "ft/term.h"

void			term_out_flush(t_term *term);

/*
** If available and if 'count' > 1, put 'cap_n' with 'count' as parameter
** otherwise, put 'cap_1' 'count' times
*/
void			term_cap_n(t_term *term, t_term_cap cap_n, t_term_cap cap_1,
					uint32_t count);

#endif
