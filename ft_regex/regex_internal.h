/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 00:19:37 by juloo             #+#    #+#             */
/*   Updated: 2015/12/27 17:53:50 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REGEX_INTERNAL_H
# define REGEX_INTERNAL_H

# include "ft/regex.h"

typedef struct s_reg_str		t_reg_str;
typedef struct s_reg_char		t_reg_char;
typedef struct s_reg_is			t_reg_is;
typedef struct s_reg_set		t_reg_set;
typedef struct s_reg			t_reg_eol;
typedef struct s_reg			t_reg_wbound;
typedef struct s_reg_group		t_reg_group;
typedef enum e_reg_type			t_reg_type;

/*
** ========================================================================== **
** Internal
** TODO: \?
** TODO: ?'\''
*/

# define REG_FAIL		((uint32_t)-1)

enum			e_reg_type
{
	REG_T_STR,
	REG_T_CHAR,
	REG_T_IS,
	REG_T_SET,
	REG_T_GROUP,
	REG_T_EOL,
	REG_T_WBOUND,
};

# define REG_F_NOT		(1 << 0)
# define REG_F_ICASE	(1 << 1)
# define REG_F_ASSERT	(1 << 2)
# define REG_F_MINIMAL	(1 << 3)

struct			s_reg
{
	uint32_t		min;
	uint32_t		max;
	uint32_t		flags;
	t_reg_type		type;
	t_reg			*or_next;
	t_reg			*next;
};

t_reg			*create_reg_str(t_sub str);
void			destroy_reg(t_reg *reg);

/*
** ========================================================================== **
** Regs
*/

struct			s_reg_str
{
	t_reg			reg;
	t_sub			str;
};

struct			s_reg_char
{
	t_reg			reg;
	char			c;
};

struct			s_reg_is
{
	t_reg			reg;
	t_is			is;
};

struct			s_reg_set
{
	t_reg			reg;
	t_bits			set[BITARRAY(128)];
};

struct			s_reg_group
{
	t_reg			reg;
	t_reg			*group;
};

uint32_t		parse_reg_is(t_sub pattern, uint32_t offset, t_reg **reg);
uint32_t		parse_reg_str(t_sub pattern, uint32_t offset, t_reg **reg);
uint32_t		parse_reg_set(t_sub pattern, uint32_t offset, t_reg **reg);
uint32_t		parse_reg_eol(t_sub pattern, uint32_t offset, t_reg **reg);
uint32_t		parse_reg_char(t_sub pattern, uint32_t offset, t_reg **reg);
uint32_t		parse_reg_wbound(t_sub pattern, uint32_t offset, t_reg **reg);
uint32_t		parse_reg_group(t_sub pattern, uint32_t offset, t_reg **reg);

#endif
