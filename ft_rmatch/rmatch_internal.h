/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmatch_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 15:03:24 by juloo             #+#    #+#             */
/*   Updated: 2015/12/10 19:23:19 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RMATCH_INTERNAL_H
# define RMATCH_INTERNAL_H

# include "ft/ft_rmatch.h"

typedef struct	s_reg
{
	int				flags;
	uint32_t		from;
	uint32_t		to;
	int				reg_len;
	char			*reg;
}				t_reg;

# ifndef REG_START
#  define REG_START		'?'
# endif

# define FLAG_R_NOT		(1 << 1)
# define FLAG_R_CASE	(1 << 2)
# define FLAG_R_EQU		(1 << 3)
# define FLAG_R_SET		(1 << 16)
# define FLAG_R_IS		(1 << 17)
# define FLAG_R_PRE		(1 << 18)
# define FLAG_R_SUB		(1 << 19)

const char		*parse_reg_pre(t_reg *reg, const char *pattern);
const char		*parse_reg_is(t_reg *reg, const char *pattern);
const char		*parse_reg_sub(t_reg *reg, const char *str);
const char		*reg_parse(t_reg *reg, const char *pattern);

const char		*reg_reg(t_reg *r, const char *s, const char *p, uint32_t l);
const char		*reg_match(const char *str, const char **pattern);
const char		*reg_test(const char *str, const char *pattern);

#endif
