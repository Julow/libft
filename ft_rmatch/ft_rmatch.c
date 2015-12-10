/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rmatch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 14:12:42 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:14:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_rmatch.h"
#include "rmatch_internal.h"

/*
** ft_rmatch
** ---
** Evaluate regex and check if 'str' match 'pattern'
** ---
** Return
**  true if the entire string match
**  false otherwise
** ---
*/

bool			ft_rmatch(const char *str, const char *pattern)
{
	const char		*tmp = reg_test(str, pattern);

	if (tmp != NULL && *tmp == '\0')
		return (true);
	return (false);
}
