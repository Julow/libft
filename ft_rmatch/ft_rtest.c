/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rtest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 17:11:02 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/27 23:45:34 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_rmatch.h"
#include "rmatch_internal.h"

/*
** ft_rtest
** ---
** Evaluate regex and check if 'str' match 'pattern'
** ---
** Return
**  the count of char that match
**  -1 if the match fail
** ---
*/

int				ft_rtest(const char *str, const char *pattern)
{
	const char		*tmp = reg_test(str, pattern);

	if (tmp == NULL)
		return (-1);
	return (tmp - str);
}
