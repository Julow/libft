/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:52:52 by jaguillo          #+#    #+#             */
/*   Updated: 2016/01/13 00:42:25 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdbool.h>
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

void			*ft_emalloc(uint32_t size);
void			*ft_memdup(const void *src, uint32_t len);

void			*ft_bzero(void *mem, uint32_t len);
void			*ft_memset(void *mem, int c, uint32_t len);

void			*ft_memcpy(void *dst, const void *src, uint32_t len);
void			*ft_memrcpy(void *dst, const void *src, uint32_t len);
void			*ft_memmove(void *dst, const void *src, uint32_t len);

void			ft_memfill(void *dst, void const *src, int size, int dst_size);
void			ft_memswap(void *mem1, void *mem2, uint32_t len);

int				ft_memcmp(const void *mem1, const void *mem2, uint32_t len);

uint32_t		ft_memstart(void const *s1, void const *s2, uint32_t n);

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
bool			ft_is(char c, t_is mask);

/*
** ========================================================================== **
** String
*/

uint32_t		ft_strlen(const char *str);
int				ft_strchri(const char *str, char c);

/*
** ========================================================================== **
** Sub
** ----
** Represent a sub-string
** -
** SUB(STR, LEN)			Sub constructor
** SUB0()					Empty sub constructor
** SUBC(STR+)				Sub constructor from literal C string
** SUB_START(S)				Equivalent to SUB(S.str, 0)
** SUB_FOR(S+, N+)			Equivalent to SUB(S.str + N, S.length - N)
** SUB_LEN(S, LEN)			Equivalent to SUB(S.str, LEN)
** SUB_OFF(A, B)			Equivalent to B.str - A.str
** SUB_SUB(S, FROM, LEN)	Equivalent to SUB(S.str + FROM, LEN)
** SUB_EQU(A+, B+)			Sub comparaison
** -
** Params marked with '+' are used several times into the macro
*/

struct			s_sub
{
	char const		*str;
	uint32_t		length;
};

# define SUB(S, L)		((t_sub){(S), (L)})
# define SUB0()			(SUB("", 0))
# define SUBC(S)		(SUB(S, sizeof(S) - 1))
# define SUB_START(S)	(SUB((S).str, 0))
# define SUB_FOR(S,N)	(SUB((S).str + (N), (S).length - (N)))
# define SUB_LEN(S,L)	(SUB((S).str, (L)))
# define SUB_OFF(A,B)	((B).str - (A).str)
# define SUB_SUB(S,F,L)	(SUB((S).str + (F), (L)))
# define SUB_EQU(A,B)	((A).length == (B).length && _SUB_EQU(A, B))
# define _SUB_EQU(A,B)	(ft_memcmp((A).str, (B).str, (A).length) == 0)

/*
** Sub constructor
** if 'from' or 'to' are negative the following is used:
**  n = ft_strlen(str) + n + 1
** Argument are swapped if from > to
*/
t_sub			ft_sub(char const *str, int from, int to);
t_sub			ft_subsub(t_sub sub, int from, int to);

/*
** Function equivalent of the macro SUB_EQU
*/
bool			ft_subequ(t_sub a, t_sub b);

/*
** Like ft_subequ but ignore case
*/
bool			ft_subequi(t_sub a, t_sub b);

/*
** Return the start index of the first sub string that match 'search'
** Return sub.length if not found
** Start search at offset 'start'
*/
uint32_t		ft_subfind(t_sub sub, t_sub search, uint32_t start);
uint32_t		ft_subfind_c(t_sub sub, char search, uint32_t start);
uint32_t		ft_subfind_is(t_sub sub, t_is search, uint32_t start);

/*
** Iterate through 'sub' looking for substrings separated by 'sep'
** 'match' should be initialized with SUBSTART(sub)
** Return false when hit the end of 'sub', true otherwise
*/
bool			ft_subnext(t_sub sub, t_sub *match, t_sub sep);
bool			ft_subnext_c(t_sub sub, t_sub *match, char sep);
bool			ft_subnext_is(t_sub sub, t_sub *match, t_is sep);

/*
** Convert the content of the sub to 'dst'
** Stop at the first invalid char
** Return the length of the converted sub string
** Return 0 on error
*/
uint32_t		ft_subto_int(t_sub sub, int32_t *dst);
uint32_t		ft_subto_uint(t_sub sub, uint32_t *dst);
uint32_t		ft_subto_float(t_sub sub, float *dst);

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
** Bit array
*/

typedef uint_fast32_t	t_bits;

# define BSIZEOF(T)				(sizeof(T) * 8)

/*
** Return a range of bit true
*/
# define BIT_RANGE(BIT,N)		((N > 0) ? BIT_RANGE_T(t_bits, BIT, N) : 0)
# define BIT_RANGE_T(T,BIT,N)	((((T)-1) >> (BSIZEOF(T) - (N))) << (BIT))

/*
** Set a range of bits
*/
void			ft_bitset(t_bits *array, uint32_t bit, uint32_t n);

/*
** Clear a range of bits
*/
void			ft_bitclear(t_bits *array, uint32_t bit, uint32_t n);

/*
** Return the required number of t_bits
** ex: t_bits array[BITARRAY(32)];
*/
# define BITARRAY(SIZE)			(((SIZE) + BSIZEOF(t_bits)-1) / BSIZEOF(t_bits))

/*
** Check if a bit is set
*/
# define BITARRAY_GET(ARRAY, B)	(BITARRAY_CHUNK_OF(ARRAY, B) & BITARRAY_BIT(B))

/*
** Set a bit
*/
# define BITARRAY_SET(ARRAY, B)	(BITARRAY_CHUNK_OF(ARRAY, B) |= BITARRAY_BIT(B))

# define BITARRAY_CHUNK_OF(A,B)	(((t_bits*)(A))[BITARRAY_CHUNK(B)])
# define BITARRAY_BIT_INDEX(B)	((B) % BSIZEOF(t_bits))
# define BITARRAY_CHUNK(B)		((B) / BSIZEOF(t_bits))
# define BITARRAY_BIT(B)		(((t_bits)1) << BITARRAY_BIT_INDEX(B))

/*
** ========================================================================== **
** Clock
*/

# define MICRO_SEC		1000000
# define NANO_SEC		1000000000

/*
** Return the current time in micro second since start
*/
uint64_t		ft_clock(uint64_t start);

/*
** Return the current time in nano second since start
*/
uint64_t		ft_nanoclock(uint64_t start);

/*
** Push the current time on the clock stack
** Return the current time in micro second
*/
uint64_t		ft_cstart(void);

/*
** Return the time elapsed since the time on the top of the clock stack
** Pop from the clock stack
*/
uint64_t		ft_cend(void);

/*
** ========================================================================== **
** Rand
** (use rand() from stdlib.h)
*/

int				ft_rand(int min, int max);
bool			ft_randbool(double chance);

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
** STATIC_ASSERT(C)			Test C at compile-time, break compilation on error
** ISSAME_ASSERT(T1, T2)	STATIC_ASSERT that test if T1 and T2 are same
** TYPE_ASSERT(A, TYPE)		STATIC_ASSERT that test if A is of type TYPE
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

# define STATIC_ASSERT(C)	 	((void)sizeof(char[1 - 2*!(C)]))
# define ISSAME_ASSERT(T1, T2)	((void)sizeof(true ? (T1*)NULL : (T2*)NULL))
# define TYPE_ASSERT(A, TYPE)	((void)sizeof(true ? &(A) : (TYPE*)NULL))

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

bool			ft_assert(char const *err, char const *func);
bool			ft_assert_hard(char const *err, char const *func);

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
