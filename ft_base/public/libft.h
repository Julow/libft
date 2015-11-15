/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:52:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/15 19:40:10 by juloo            ###   ########.fr       */
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

# define MASK(f,m)		((m) == ((f) & (m)))
# define FLAG(f,b)		(((f) & (1 << (b))) != 0)
# define BIT(b)			(1 << (b))

# define DB(l,v)		{[0 ... ((l) - 1)] = (v)}

# define VOID			((void)0)

# ifndef NULL
#  define NULL			((void*)0)
# endif

# ifndef EOF
#  define EOF			-1
# endif

# define IGNORE(f)		((void)((f) + 1))

# define CAT(a,b)		a##b

# define STR(s)			#s
# define STR_VALUE(s)	STR(s)

# define G_ARRAY_LEN(g)	((int)(sizeof(g) / sizeof(*(g))))

# define S(t,l)			(sizeof(t) * (l))

# define ENDOF(s)		(((void*)s) + sizeof(*(s)))

# define BOOL_OF(E)		((E) ? true : false)

# define _INT_MIN(T)	(((T)1) << (sizeof(T) * 8 - 1))
# define _UINT_MIN(T)	((T)0)

# define IS_UNSIGNED(T)	(((T)-1) > ((T)0))

# define INT_MIN(T)		(IS_UNSIGNED(T) ? _UINT_MIN(T) : _INT_MIN(T))
# define INT_MAX(T)		(~(INT_MIN(T)))

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
# else
#  define MAL			EMAL
#  define MAL1			EMAL1
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

typedef int		t_is;

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
** TODO: deprecate ft_str* (except ft_strlen)
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
** Math
*/

# define MIN(a,b)		(((a) < (b)) ? (a) : (b))
# define MAX(a,b)		(((a) > (b)) ? (a) : (b))
# define ABS(a)			(((a) < 0) ? -(a) : (a))

# define CEIL(n)		((int)(1 + (n)))
# define ROUND(n)		((int)(0.5 + (n)))
# define FLOOR(n)		((int)(n))

# define ISNAN(d)		((d) != (d))

int				ft_abs(int a);
int				ft_max(int a, int b);
int				ft_min(int a, int b);

/*
** ========================================================================== **
*/

#endif
