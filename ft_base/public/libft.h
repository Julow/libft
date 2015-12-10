/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:52:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 17:40:07 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdint.h>

/*
** ========================================================================== **
** Config
** ---
** REG_START
** BUFF_SIZE
** FTOUT_BUFF
** GNL_BUFF
** MEM_TYPE
** EMAL_ERROR
** EMAL_EXIT
** NO_EMAL
** ---
*/

# ifdef FT_CONFIG
#  include FT_CONFIG
# endif

# ifndef FTOUT_BUFF
#  define FTOUT_BUFF	512
# endif
# ifndef MEM_TYPE
#  define MEM_TYPE		unsigned long long int
# endif
# ifndef EMAL_ERROR
#  define EMAL_ERROR	"Error: not enougth memory"
# endif
# ifndef EMAL_EXIT
#  define EMAL_EXIT		1
# endif

/*
** ========================================================================== **
** Types
*/

typedef unsigned char			t_byte;
typedef unsigned char			t_uchar;
typedef unsigned int			t_uint;
typedef long long int			t_long;
typedef unsigned long long int	t_ulong;

typedef enum e_bool				t_bool;

typedef struct s_sub			t_sub;

# define V(v)			((void*)(v))

# define VOID			((void)0)

# ifndef NULL
#  define NULL			((void*)0)
# endif

# ifndef EOF
#  define EOF			(-1)
# endif

# define IGNORE(VAL)	((void)sizeof(VAL))

# define CAT(a,b)		a##b

# define STR_VALUE(s)	#s
# define TO_STR(s)		STR_VALUE(s)

# define ARRAY_LEN(g)	((int)(sizeof(g) / sizeof(*(g))))

# define S(t,l)			(sizeof(t) * (l))

# define ENDOF(s)		(((void*)s) + sizeof(*(s)))

# define BOOL_OF(E)		((E) ? true : false)

# define MIN(a,b)		(((a) < (b)) ? (a) : (b))
# define MAX(a,b)		(((a) > (b)) ? (a) : (b))
# define ABS(a)			(((a) < 0) ? -(a) : (a))

# define CEIL(n)		((int)(1 + (n)))
# define ROUND(n)		((int)(0.5 + (n)))
# define FLOOR(n)		((int)(n))

# define ISNAN(d)		((d) != (d))

enum			e_bool
{
	false = 0,
	true = 1
};

/*
** ========================================================================== **
** Memory
*/

# define EMAL(t,l)		((t*)ft_emalloc(sizeof(t) * (l)))
# define EMAL1(t)		((t*)ft_emalloc(sizeof(t)))

# ifdef NO_EMAL
#  define MAL(t,l)		((t*)malloc(sizeof(t) * (l)))
#  define MAL1(t)		((t*)malloc(sizeof(t)))
#  define NEW			MAL1
# else
#  define MAL			EMAL
#  define MAL1			EMAL1
#  define NEW			MAL1
# endif

void			*ft_emalloc(t_uint size);
void			*ft_memdup(const void *src, t_uint len);

void			*ft_bzero(void *mem, t_uint len);
void			*ft_memset(void *mem, int c, t_uint len);

void			*ft_memcpy(void *dst, const void *src, t_uint len);
void			*ft_memrcpy(void *dst, const void *src, t_uint len);
void			*ft_memmove(void *dst, const void *src, t_uint len);

void			ft_memfill(void *dst, void const *src, int size, int dst_size);
void			ft_memswap(void *mem1, void *mem2, t_uint len);

int				ft_memcmp(const void *mem1, const void *mem2, t_uint len);

t_uint			ft_memstart(void const *s1, void const *s2, t_uint n);

/*
** ========================================================================== **
** Char classification
** ----
** '\0' is not classified
*/

# define IS_GRAPH		(IS_PUNCT | IS_ALNUM)
# define IS_PRINT		(IS_GRAPH | IS_BLANK)
# define IS_CNTRL		(1 << 1)

# define IS_BLANK		(1 << 2)
# define IS_WHITE		(1 << 3)
# define IS_SPACE		(IS_WHITE | IS_BLANK)

# define IS_DIGIT		(1 << 4)
# define IS_LOWER		(1 << 5)
# define IS_UPPER		(1 << 6)
# define IS_ALPHA		(IS_LOWER | IS_UPPER)
# define IS_ALNUM		(IS_DIGIT | IS_ALPHA)
# define IS_WORD		(IS_ALNUM | IS_UNDERSCORE)

# define IS_PUNCT		(1 << 7)
# define IS_XDIGIT		(IS_DIGIT | IS_XALPHA)

# define IS_XALPHA		(1 << 8)
# define IS_UNDERSCORE	(1 << 9)

typedef uint32_t	t_is;

extern t_is		g_is_table[];

# define IS(c,f)		(g_is_table[(unsigned char)(c)] & (f))

/*
** ft_is function is equivalent to IS macro
** also the IS macro use only once it's arguments
*/
t_bool			ft_is(char c, t_is mask);

/*
** ========================================================================== **
** String
*/

t_uint			ft_strlen(const char *str);
int				ft_strchri(const char *str, char c);

/*
** ========================================================================== **
** Sub
** ----
** Represent a sub-string
*/

# define SUB(s,l)		((t_sub){(s), (l)})
# define SUB0()			(SUB("", 0))
# define SUBC(s)		SUB(s, sizeof(s) - 1)

struct			s_sub
{
	char const		*str;
	int				length;
};

t_sub			ft_sub(char const *str, int from, int to);

/*
** ========================================================================== **
** Conversion
*/

# define BASE_2			"01"
# define BASE_8			"01234567"
# define BASE_10		"0123456789"
# define BASE_16		"0123456789ABCDEF"
# define BASE_16_LOWER	"0123456789abcdef"
# define BASE_36		"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

# define LOWER(c)		(((c) >= 'A' && (c) <= 'Z') ? (c) + 32 : (c))
# define UPPER(c)		(((c) >= 'a' && (c) <= 'z') ? (c) - 32 : (c))

int				ft_atoib(const char *str, int *nb);

char			ft_escape(char c);
char			ft_unescape(char c);

/*
** ========================================================================== **
** Clock
*/

# define MICRO_SEC		1000000
# define NANO_SEC		1000000000

/*
** Return the current time in micro second since start
*/
t_ulong			ft_clock(t_ulong start);

/*
** Return the current time in nano second since start
*/
t_ulong			ft_nanoclock(t_ulong start);

/*
** ========================================================================== **
** Rand
** (use rand() from stdlib.h)
*/

int				ft_rand(int min, int max);
t_bool			ft_randbool(double chance);

/*
** ========================================================================== **
** Misc
*/

/*
** ft_getenv
** -
** Retrieve an environ variable
** -
** Return a ptr to the value if found
** Return NULL if not found
*/
char const		*ft_getenv(t_sub key);

int				ft_abs(int a);
int				ft_max(int a, int b);
int				ft_min(int a, int b);

/*
** ========================================================================== **
** Assert
** -
** TRACE(MSG)				Print the current code location
** ASSERT(C, MSG)			Test C, print on fail, do nothing on success
** TEST_ASSERT(C, MSG)		Test C, print on success, do nothing on error
** DEBUG_ASSERT(C, MSG)		Same as ASSERT(C, MSG) but print on success
** HARD_ASSERT(C, MSG)		Same as ASSERT(C, MSG) but exit on error
** -
** ASSERT(C, MSG)
** 		C		Tested code (everything that fit in 'if (( C ))')
** 		MSG		Optionnal description (literal string only)
** 	Return false if C fail, true otherwise
** -
** TRACE(MSG)
** 		MSG		Optionnal description (literal string only)
** -
** Defining ASSERT_DISABLE will disable all asserts
*/

# ifdef ASSERT_DISABLE
#  define TRACE(...)			IGNORE(NULL)
#  define ASSERT(C, ...)		BOOL_OF(sizeof(C) || 1)
#  define TEST_ASSERT(C, ...)	BOOL_OF(sizeof(C) || 1)
#  define DEBUG_ASSERT(C, ...)	BOOL_OF(sizeof(C) || 1)
#  define HARD_ASSERT(C, ...)	BOOL_OF(sizeof(C) || 1)
# else
#  define TRACE(...)			_ASSERT_TRACE(""__VA_ARGS__)
#  define ASSERT(C, ...)		((C)||_ASSERT_CALL(STR_VALUE(C),""__VA_ARGS__))
#  define TEST_ASSERT(C, ...)	((C)&&_ASSERT_DCALL(STR_VALUE(C),""__VA_ARGS__))
#  define DEBUG_ASSERT(C, ...)	((C)&&_ASSERT_DEBUG(STR_VALUE(C),""__VA_ARGS__))
#  define HARD_ASSERT(C, ...)	((C)||_ASSERT_HCALL(STR_VALUE(C),""__VA_ARGS__))
# endif

t_bool			ft_assert(char const *err, char const *func);
t_bool			ft_assert_hard(char const *err, char const *func);

# define _ASSERT_LOCATION	__FILE__ ":" TO_STR(__LINE__) " "
# define _ASSERT_CODE(C)	"[\033[31m" C "\033[39m] "
# define _ASSERT_MIN(C)		_ASSERT_CODE(C) _ASSERT_LOCATION "\033[90m"
# define _ASSERT_FULL(C,V)	_ASSERT_CODE(C) V " \033[90m" _ASSERT_LOCATION
# define _ASSERT_ERR(C,V)	(sizeof(V)==1)?_ASSERT_MIN(C):_ASSERT_FULL(C,V)
# define _ASSERT_CALL(C,V)	ft_assert(_ASSERT_ERR(C, V), __func__)
# define _ASSERT_HCALL(C,V)	ft_assert_hard(_ASSERT_ERR(C, V), __func__)
# define _ASSERT_DCALL(C,V)	!ft_assert(_ASSERT_ERR("\033[32m" C, V), __func__)
# define _ASSERT_TRACE(V)	ft_assert(_ASSERT_ERR("\033[33mTRACE",V),__func__)
# define _ASSERT_DEBUG(C,V)	_ASSERT_DCALL(C, V) || _ASSERT_CALL(C, V)

/*
** ========================================================================== **
*/

#endif
