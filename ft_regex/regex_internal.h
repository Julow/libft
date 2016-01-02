/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 00:19:37 by juloo             #+#    #+#             */
/*   Updated: 2016/01/02 23:07:00 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REGEX_INTERNAL_H
# define REGEX_INTERNAL_H

# include "ft/regex.h"

typedef struct s_reg_str		t_reg_str;
typedef struct s_reg_is			t_reg_is;
typedef struct s_reg_set		t_reg_set;
typedef struct s_reg_group		t_reg_group;
typedef struct s_reg			t_reg_sol;
typedef struct s_reg			t_reg_eol;
typedef struct s_reg			t_reg_wbound;
typedef enum e_reg_type			t_reg_type;

typedef struct s_parse_reg		t_parse_reg;
typedef struct s_parse_reg_n	t_parse_reg_n;

typedef struct s_rmatch			t_rmatch;
typedef struct s_exec_reg		t_exec_reg;

/*
** ========================================================================== **
** Internal
** TODO: \?
** TODO: ?'\''
*/

# define REG_FAIL		((uint32_t)-1)

/*
** ========================================================================== **
** Reg def
*/

enum			e_reg_type
{
	REG_T_STR,
	REG_T_IS,
	REG_T_SET,
	REG_T_GROUP,
	REG_T_EOL,
	REG_T_SOL,
	REG_T_WBOUND,
	__REG_T_COUNT
};

# define REG_F_NOT		(1 << 0)
# define REG_F_ICASE	(1 << 1)
# define REG_F_ASSERT	(1 << 2)
# define REG_F_MINIMAL	(1 << 3)
# define REG_F_UNUSED	(1 << 4)
# define REG_F_CAPTURE	(1 << 5)

struct			s_reg
{
	uint32_t		min;
	uint32_t		max;
	uint32_t		flags;
	uint32_t		capture_index;
	t_reg_type		type;
	t_reg			*or_next;
	t_reg			*next;
};

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

/*
** ========================================================================== **
** Reg exec
*/

struct			s_rmatch
{
	char const		*str;
	uint32_t		len;
	t_sub			*captures;
};

/*
** the exec function have to handle '!' and 'i' flags
** return REG_FAIL on error, incremented offset otherwise
** -
** if no_bt is true, change the expected behavior of the exec function:
**   it have to handle every flags, capture and backtracking
*/
struct			s_exec_reg
{
	uint32_t		(*exec)(t_rmatch*, t_reg const*, uint32_t);
	bool			no_bt;
};

uint32_t		exec_reg_str(t_rmatch *m, t_reg_str const *reg, uint32_t offset);
uint32_t		exec_reg_is(t_rmatch *m, t_reg_is const *reg, uint32_t offset);
uint32_t		exec_reg_set(t_rmatch *m, t_reg_set const *reg, uint32_t offset);
uint32_t		exec_reg_group(t_rmatch *m, t_reg_group const *reg, uint32_t offset);
uint32_t		exec_reg_eol(t_rmatch *m, t_reg_eol const *reg, uint32_t offset);
uint32_t		exec_reg_sol(t_rmatch *m, t_reg_eol const *reg, uint32_t offset);
uint32_t		exec_reg_wbound(t_rmatch *m, t_reg_wbound const *reg, uint32_t offset);

/*
** exec a reg
*/
uint32_t		exec_reg(t_rmatch *m, t_reg const *reg, uint32_t offset);

/*
** exec next reg
** handle '=' flag and capture
*/
uint32_t		exec_reg_next(t_rmatch *m, t_reg const *reg,
					uint32_t start, uint32_t offset);

/*
** ========================================================================== **
** Reg parse
*/

struct			s_parse_reg
{
	char const		*str;
	uint32_t		len;
	uint32_t		capture_index;
	uint32_t		capture_count;
	t_parse_reg_n	*named_regs;
};

struct			s_parse_reg_n
{
	t_sub			name;
	t_reg			*reg;
	t_parse_reg_n	*prev;
};

uint32_t		parse_reg_str(t_parse_reg *p, uint32_t offset, t_reg **reg);
uint32_t		parse_reg_is(t_parse_reg *p, uint32_t offset, t_reg **reg);
uint32_t		parse_reg_set(t_parse_reg *p, uint32_t offset, t_reg **reg);
uint32_t		parse_reg_group(t_parse_reg *p, uint32_t offset, t_reg **reg);
uint32_t		parse_reg_eol(t_parse_reg *p, uint32_t offset, t_reg **reg);
uint32_t		parse_reg_sol(t_parse_reg *p, uint32_t offset, t_reg **reg);
uint32_t		parse_reg_wbound(t_parse_reg *p, uint32_t offset, t_reg **reg);
uint32_t		parse_reg_named(t_parse_reg *p, uint32_t offset, t_reg **reg);

uint32_t		parse_reg(t_parse_reg *p, uint32_t offset, t_reg **reg);

t_reg			*append_reg_next(t_reg *reg, t_reg *next);

t_reg			*create_reg_str(t_sub str);
void			destroy_reg(t_reg *reg);

#endif
