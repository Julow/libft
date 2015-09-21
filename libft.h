/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:52:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/21 12:37:01 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

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
** Debug
*/

# define _DEBUG	__FILE__, __LINE__, __func__

# define DEBUG(f,...)	(ft_printf("%s:%d [%s] " f "\n", _DEBUG, ##__VA_ARGS__))
# define TRACE			(DEBUG("TRACE", NULL))

/*
** ========================================================================== **
** Types
*/

enum			e_bool
{
	false = 0,
	true = 1
};

typedef unsigned char			t_byte;
typedef unsigned char			t_uchar;
typedef unsigned int			t_uint;
typedef long long int			t_long;
typedef unsigned long long int	t_ulong;

typedef struct s_vector			t_vector;
typedef struct s_list			t_list;
typedef struct s_hmap			t_hmap;
typedef struct s_deque			t_deque;
typedef struct s_dstr			t_dstr;

typedef struct s_deque_it		t_deque_it;

typedef enum e_bool				t_bool;

typedef struct s_sub			t_sub;

typedef struct s_var			t_var;

typedef struct s_out			t_out;
typedef struct s_buff			t_buff;

typedef struct s_args			t_args;
typedef struct s_opt			t_opt;

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

# define S(t,l)			(sizeof(t) * (l))

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

t_bool			ft_match(char *str, char *pattern);
int				ft_nmatch(char *str, char *pattern);
t_bool			ft_hidenp(char *hide, char *str);

t_bool			ft_sisint(const char *s);

int				ft_strchri(const char *str, char c);
int				ft_strichri(const char *str, char c);
char			*ft_strchr(const char *s, char c);

t_uint			ft_strcskipe(const char *str, const char *skip);
t_bool			ft_strequ(const char *s1, const char *s2);

t_bool			ft_strncase(const char *s1, const char *s2, t_uint n);

char			*ft_strdup(const char *str);
char			*ft_strndup(const char *src, t_uint len);

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
t_sub			ft_subsub(t_sub sub, int from, int to);

t_bool			ft_subequ(t_sub a, t_sub b);

int				ft_subtrim(t_sub *sub, t_is mask);
int				ft_subtrimr(t_sub *sub, t_is mask);
int				ft_subtriml(t_sub *sub, t_is mask);

t_bool			ft_subnext(t_sub *sub, t_is mask);
t_bool			ft_subnextc(t_sub *sub, char c);
int				ft_subcount(t_sub sub, t_is mask);
int				ft_subextract(t_sub sub, t_sub *dst, int max, t_is mask);

int				ft_subindex(t_sub sub, char c);
int				ft_subchr(t_sub sub, t_is mask);

int				ft_subint(t_sub sub, int *dst);

/*
** ft_subfloat
** -
** Parse a float number
** Stop at the first invalid char
** Store result in the *f param
** -
** Return the length of the float (in the string)
**  on error return 0 (0 char parsed)
** -
** Allow hexa (0x) and binary (0b) number
** -
** Valid float:
**  -?[0-9]*([.,][0-9]*)?
*/
int				ft_subfloat(t_sub sub, float *f);

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

int				ft_atoi(const char *str);
t_long			ft_atol(const char *str);
double			ft_atod(const char *str);

int				ft_atoib(const char *str, int *nb);
int				ft_atoub(const char *str, t_uint *nb);

int				ft_itoab(int n, char *buff);

t_ulong			ft_basetoi(const char *str, const char *base);

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

int				ft_exec(char **argv, char **env);

char			*ft_getenv(char const *name, char **env);

/*
** ========================================================================== **
** Sort
*/

void			ft_simplesort(void **tab, int length, int (*cmp)());
void			ft_mergesort(void **tab, int length, int (*cmp)());
void			ft_bubblesort(void **tab, int length, int (*cmp)());
void			ft_insertsort(void **tab, int length, int (*cmp)());
void			ft_quicksort(void **tab, int length, int (*cmp)());

t_bool			ft_issort(void **tab, int length, int (*cmp)());

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
** get_next_line
*/

int				get_next_line(int const fd, t_sub *line);

/*
** ========================================================================== **
** A format sequence be like:
**    %[flags][width][.precision]format
** flags can be 0 or more: '#', ' ', '-', '+', '^', '0', ''', '>', 'm', 'M'
** width is a positive integer
** precision is a positive integer or '*', precision start with '.'
** format can be one of "%sSdDoOuUxXicCnpfFeE"
** A meta sequence be like:
**    {meta_name}
** (list of meta in srcs/ft_printf/parse_meta.c)
** -
** ft_printf
** -
** Process the format sequence like printf and print the result to stdout
** -
** Return the total of char printed.
*/

int				ft_printf(const char *format, ...);
int				ft_fdprintf(const int fd, const char *format, ...);
int				ft_sprintf(char *dst, char const *format, ...);
int				ft_snprintf(char *dst, int max_len, char const *format, ...);

/*
** ========================================================================== **
*/

#endif
