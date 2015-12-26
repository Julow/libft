/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:56:34 by juloo             #+#    #+#             */
/*   Updated: 2015/12/26 18:06:57 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REGEX_H
# define REGEX_H

# include "ft/libft.h"

typedef struct s_regex			t_regex;
typedef struct s_reg			t_reg;

/*
** ========================================================================== **
** Regex
*/

struct			s_regex
{
	t_reg			*reg;
};

/*
** Compile a regex
** Return true otherwise or false on error
*/
bool			ft_rcompile(t_regex *dst, t_sub pattern);

/*
** Free a regex
** (Do not free the 'regex' pointer)
*/
void			ft_rdestroy(t_regex *regex);

#endif
