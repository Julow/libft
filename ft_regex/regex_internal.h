/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 00:19:37 by juloo             #+#    #+#             */
/*   Updated: 2016/02/10 16:54:59 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REGEX_INTERNAL_H
# define REGEX_INTERNAL_H

# include "ft/regex.h"

typedef struct s_reg_str		t_reg_str;
typedef struct s_reg_set		t_reg_set;
typedef struct s_reg_group		t_reg_group;
typedef struct s_reg			t_reg_sol;
typedef struct s_reg			t_reg_eol;
typedef struct s_reg			t_reg_wbound;
typedef struct s_reg_cstr		t_reg_cstr;
typedef enum e_reg_type			t_reg_type;

typedef struct s_parse_reg		t_parse_reg;
typedef struct s_parse_reg_n	t_parse_reg_n;

typedef struct s_exec_reg		t_exec_reg;

/*
** ========================================================================== **
** Internal
** TODO: \?
** TODO: ?'\''
*/

# define REG_FAIL		((uint32_t)-1)
# define REG_INFINITY	(((uint32_t)-1)>>1)

/*
** ========================================================================== **
** Reg def
*/

enum			e_reg_type
{
	REG_T_STR,
	REG_T_SET,
	REG_T_GROUP,
	REG_T_EOL,
	REG_T_SOL,
	REG_T_WBOUND,
	REG_T_CSTR,
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

struct			s_reg_set
{
	t_reg			reg;
	t_is			is;
	t_bits			set[BITARRAY(128)];
};

struct			s_reg_group
{
	t_reg			reg;
	t_reg			*group;
};

struct			s_reg_cstr
{
	t_reg			reg;
	uint32_t		index;
};

/*
** ========================================================================== **
** Reg exec
*/

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
uint32_t		exec_reg_set(t_rmatch *m, t_reg_set const *reg, uint32_t offset);
uint32_t		exec_reg_group(t_rmatch *m, t_reg_group const *reg, uint32_t offset);
uint32_t		exec_reg_eol(t_rmatch *m, t_reg_eol const *reg, uint32_t offset);
uint32_t		exec_reg_sol(t_rmatch *m, t_reg_sol const *reg, uint32_t offset);
uint32_t		exec_reg_wbound(t_rmatch *m, t_reg_wbound const *reg, uint32_t offset);
uint32_t		exec_reg_cstr(t_rmatch *m, t_reg_cstr const *reg, uint32_t offset);

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
	uint32_t		err_offset;
	t_sub			err_str;
};

/*
** Set err_offset and err_str in P
** Return REG_FAIL
*/
# define REG_ERROR(P,S,O)	((P)->err_offset=O),((P)->err_str=SUBC(S)),REG_FAIL

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
uint32_t		parse_reg_block(t_parse_reg *p, uint32_t offset, t_reg **reg);
bool			parse_reg_block_is(t_sub sub, t_reg **reg);

uint32_t		parse_reg(t_parse_reg *p, uint32_t offset, t_reg **reg);

uint32_t		parse_regex(t_parse_reg *p, uint32_t offset, t_reg **reg,
					char end);

t_reg			*append_reg_next(t_reg *reg, t_reg *next);

uint32_t		ft_subchr_e(t_sub sub, uint32_t offset, char chr);

t_reg			*create_reg_str(t_sub str);
void			destroy_reg(t_reg *reg);

#endif
