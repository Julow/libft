/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 00:19:37 by juloo             #+#    #+#             */
/*   Updated: 2015/12/31 14:09:03 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REGEX_INTERNAL_H
# define REGEX_INTERNAL_H

# include "ft/regex.h"

typedef struct s_reg_str		t_reg_str;
typedef struct s_reg_is			t_reg_is;
typedef struct s_reg_set		t_reg_set;
typedef struct s_reg			t_reg_eol;
typedef struct s_reg			t_reg_wbound;
typedef struct s_reg_group		t_reg_group;
typedef struct s_reg_va			t_reg_va;
typedef enum e_reg_va_t			t_reg_va_t;
typedef enum e_reg_type			t_reg_type;
typedef struct s_parse_reg		t_parse_reg;
typedef struct s_parse_reg_n	t_parse_reg_n;

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
	REG_T_IS,
	REG_T_SET,
	REG_T_GROUP,
	REG_T_EOL,
	REG_T_WBOUND,
	REG_T_VA,
	__REG_T_COUNT
};

# define REG_F_NOT		(1 << 0)
# define REG_F_ICASE	(1 << 1)
# define REG_F_ASSERT	(1 << 2)
# define REG_F_MINIMAL	(1 << 3)
# define REG_F_UNUSED	(1 << 4)

struct			s_parse_reg
{
	char const		*str;
	uint32_t		len;
	uint32_t		va_index;
	t_parse_reg_n	*named_regs;
};

struct			s_parse_reg_n
{
	t_sub			name;
	t_reg			*reg;
	t_parse_reg_n	*prev;
};

struct			s_reg
{
	uint32_t		min;
	uint32_t		max;
	uint32_t		flags;
	t_reg_type		type;
	t_reg			*or_next;
	t_reg			*next;
};

struct			s_reg_type
{
	uint32_t		reg_size;
	uint32_t		(*parse)(t_parse_reg*, uint32_t, t_reg**);
};

uint32_t		parse_reg(t_parse_reg *p, uint32_t offset, t_reg **reg);

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

enum			e_reg_va_t
{
	REG_VA_T_SUB,
	REG_VA_T_STR,
	REG_VA_T_REGEX,
};

struct			s_reg_va
{
	t_reg			reg;
	uint32_t		index;
	t_reg_va_t		type;
};

uint32_t		parse_reg_is(t_parse_reg *p, uint32_t offset, t_reg **reg);
uint32_t		parse_reg_str(t_parse_reg *p, uint32_t offset, t_reg **reg);
uint32_t		parse_reg_set(t_parse_reg *p, uint32_t offset, t_reg **reg);
uint32_t		parse_reg_eol(t_parse_reg *p, uint32_t offset, t_reg **reg);
uint32_t		parse_reg_wbound(t_parse_reg *p, uint32_t offset, t_reg **reg);
uint32_t		parse_reg_group(t_parse_reg *p, uint32_t offset, t_reg **reg);
uint32_t		parse_reg_named(t_parse_reg *p, uint32_t offset, t_reg **reg);
uint32_t		parse_reg_va(t_parse_reg *p, uint32_t offset, t_reg **reg);

#endif
