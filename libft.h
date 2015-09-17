/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:52:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/17 16:37:14 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** ========================================================================== **
** Cheat Sheet Shit
** ---
** Registers
**	qword			dword		word	byte
** 	64				32			16		[8	8]
** -
** 	rax				eax			ax		ah	al 		Return 1
** 	rbx				ebx			bx		bh	bl 		(Callee saved)
** 	rcx				ecx			cx		ch	cl 		Arg 4 + Counter
** 	rdx				edx			dx		dh	dl 		Arg 3 + Return 2
** 	rsi				esi			si			sil		Arg 2
** 	rdi				edi			di			dil		Arg 1
** 	rbp				ebp			bp			bpl		(Callee saved)
** 	rsp				esp			sp			spl		Stack ptr (Callee saved)
** 	r8				r8d			r8w			r8b		Arg 5
** 	r9				r9d			r9w			r9b		Arg 6
** 	r10				r10d		r10w		r10b	Arg 7
** 	r11				r11d		r11w		r11b	Tmp
** 	r12				r12d		r12w		r12b	(Callee saved)
** 	r13				r13d		r13w		r13b	(Callee saved)
** 	r14				r14d		r14w		r14b	(Callee saved)
** 	r15				r15d		r15w		r15b	(Callee saved)
** -
**  256				128
** -
**  ymm0			xmm0
** ...
**  ymm15			xmm15
** ---
** ========================================================================== **
** ---
** Signals
** 			Name			Action			Comment
** -
**  1		SIGHUP			Terminate		Hangup or Parent terminated
**  2		SIGINT			Terminate		^C
**  3		SIGQUIT			Core Dump		^\
**  4		SIGILL			Core Dump		Illegal Instruction
**  5		SIGTRAP			Core Dump		Breakpoint
**  6		SIGABRT			Core Dump		Abort
**  		SIGBUS			Core Dump		Bus error
**  8		SIGFPE			Core Dump		Floating point exception
**  9		SIGKILL			! Terminate		Kill
**  		SIGUSR1			Terminate		User 1
**  11		SIGSEGV			Core Dump		Segmentation fault
**  		SIGUSR2			Terminate		User 2
**  13		SIGPIPE			Terminate		Broken pipe
**  14		SIGALRM			Terminate		Timer
**  15		SIGTERM			Terminate		Terminate
**  		SIGSTKFLT		Terminate		Stack fault
**  		SIGCHLD			Ignore			Child terminated
**  		SIGCONT			Continue		Continue after a Stop
**  		SIGSTOP			! Stop			Stop
**  		SIGTSTP			Stop			^Z
**  		SIGTTIN			Stop			Terminal input
**  		SIGTTOU			Stop			Terminal output
**  		SIGURG			Ignore			Urgent
**  		SIGXCPU			Core Dump		CPU time limit
**  		SIGXFSZ			Core Dump		File size limit
**  		SIGVTALRM		Terminate		Virtual alarm
**  		SIGPROF			Terminate		Profiling timer
**  		SIGWINCH		Ignore			Window resize
**  		SIGIO			Terminate		-
**  		SIGPWR			Terminate		Power failure
**  		SIGSYS			Core Dump		-
** ---
** ========================================================================== **
*/

/*
** ========================================================================== **
** Config
** ---
** REG_START
** BUFF_SIZE
** FTOUT_BUFF
** GNL_BUFF
** ARRAY_CHUNK
** TAB_CHUNK
** STRING_CHUNK
** MEM_TYPE
** EMAL_ERROR
** EMAL_EXIT
** NO_EMAL
** DEBUG_MODE
** ---
*/

# ifdef FT_CONFIG
#  include FT_CONFIG
# endif

# ifndef FTOUT_BUFF
#  define FTOUT_BUFF	512
# endif
# ifndef ARRAY_CHUNK
#  define ARRAY_CHUNK	64
# endif
# ifndef TAB_CHUNK
#  define TAB_CHUNK		32
# endif
# ifndef STRING_CHUNK
#  define STRING_CHUNK	128
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

# define TUCHAR			unsigned char
# define TUINT			unsigned int
# define TLONG			long long int
# define TULONG			unsigned long long int

typedef TUCHAR	t_byte;
typedef TUCHAR	t_uchar;
typedef TUINT	t_uint;
typedef TLONG	t_long;
typedef TULONG	t_ulong;
typedef TLONG	t_big;

# undef TUCHAR
# undef TUINT
# undef TLONG
# undef TULONG

typedef enum	e_bool
{
	false = 0,
	true = 1
}				t_bool;

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
** TODO: deprecate ft_is*
** TODO: deprecate ft_str* (except ft_strlen)
*/

t_uint			ft_strlen(const char *str);

t_bool			ft_match(char *str, char *pattern);
int				ft_nmatch(char *str, char *pattern);
t_bool			ft_hidenp(char *hide, char *str);

t_bool			ft_isalnum(int c);
t_bool			ft_isalpha(int c);
t_bool			ft_isascii(int c);
t_bool			ft_isdigit(int c);
t_bool			ft_isprint(int c);
t_bool			ft_isspace(int c);
t_bool			ft_isword(int c);
t_bool			ft_isrange(int c, int from, int to);
t_bool			ft_iswhite(int c);

t_bool			ft_isato(const char *str);
t_bool			ft_isnumber(const char *str);

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
# define SUBC(s)		SUB(s, sizeof(s) - 1)

typedef struct	s_sub
{
	char const		*str;
	int				length;
}				t_sub;

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

int				ft_toupper(int c);
int				ft_tolower(int c);

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

void			ft_splitfree(char **split);

/*
** ========================================================================== **
** Regex
** ---
** ?<opt><n><match>
** ?<opt><n><match>|<opt><n><match>| ...
** ---
** opt: (cummulable but need to be in this order)
** - !		Match not (invert matching)
** - i		Lower case (str is treated as lower, match need to be lower case)
** ---
** n:
** - 1		Match 1 (Default)
** - ?		Match 0 or 1
** - *		Match 0 or more
** - +		Match 1 or more
** - n		Match n
** - n,		Match n or more
** - n,N	Match n to N
** ---
** match:
** - .		Match any char (except '\0')
** - w		ft_isword		[a-zA-Z0-9_]
** - a		ft_isalpha		[a-zA-Z]
** - n		ft_isalnum		[a-zA-Z0-9]
** - c		ft_isascii		.
** - d		ft_isdigit		[0-9]
** - p		ft_isprint		[ -~]
** - s		ft_isspace		[ \t]
** - h		ft_iswhite		[ \t\n\r\v\f]
** - :a		Match a char
** - &i		Match a valid int
** - [abc]	Match a set of char
** - [a-z]	Match an interval of char (cummulable with char set)
** - 'abc'	Match a string
** - (abc)	Match a string (can contains regex)
** ---
** TODO:
** - global lower case mode (?i;)
** - str end (?$)
** - sprintf like parsing (using va_arg)
** ---
*/

t_bool			ft_rmatch(const char *str, const char *pattern);
int				ft_rtest(const char *str, const char *pattern);
t_bool			ft_rfind(t_sub *dst, const char *str, const char *pattern);
t_bool			ft_rnext(t_sub *last, const char *pattern);

int				ft_matchint(const char *str);

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
** Write
*/

int				ft_puts(const char *s);
int				ft_putchar(char c);
int				ft_putnchar(char c, int n);
int				ft_putstr(const char *str);
int				ft_putlstr(const char *str, int len);
int				ft_putendl(const char *s);
int				ft_putnbr(int n);
int				ft_putlong(t_long n);
int				ft_putchar_fd(char c, int fd);
int				ft_putnchar_fd(char c, int n, int fd);
int				ft_putstr_fd(const char *s, int fd);
int				ft_putlstr_fd(const char *s, int len, int fd);
int				ft_putendl_fd(const char *s, int fd);
int				ft_putnbr_fd(int n, int fd);
int				ft_putlong_fd(t_long n, int fd);

/*
** ========================================================================== **
** Use the struct s_buff (t_buff) to read and parse a file
**  BUFF() macro init a file buff
** Can parse simple string
**  SBUFF() macro init a string buff
*/

# define BI(b)			((b)->i < (b)->length)
# define BG(b)			(BI(b) ? (b)->data[(b)->i] : ft_buffget(b))
# define BR(b)			(BI(b) ? (b)->data[(b)->i++] : ft_readbuff(b))
# define BIS(b,c)		(BG(b) == c && ++((b)->i))
# define BIF(b,f)		((f)(BG(b)) && ++((b)->i))

# define BF_EOF			20
# define BF_STR			21

# define BEOF(b)		(FLAG((b)->fd, BF_EOF) || (BSTR(b) && !BI(b)))
# define BSTR(b)		FLAG((b)->fd, BF_STR)
# define BFD(b)			((b)->fd & 0xFF)

# define BUFF(f,b,l)	((t_buff){(b), 0, 0, (l), (f) & 0xFF})
# define SBUFF(s,l)		((t_buff){(s), 0, (l), (l), -1 & 0xFF | BIT(BF_STR)})

typedef struct	s_buff
{
	char			*data;
	int				i;
	int				length;
	int				buff_len;
	int				fd;
}				t_buff;

char			ft_readbuff(t_buff *buff);
char			ft_buffget(t_buff *buff);
void			ft_buffclear(t_buff *buff);

t_bool			ft_parseint(t_buff *buff, int *nb);
t_bool			ft_parselong(t_buff *buff, t_long *nb);
t_bool			ft_parsebase(t_buff *buff, const char *base, t_ulong *nb);
t_bool			ft_parsebasei(t_buff *buff, const char *base, t_ulong *nb);
t_bool			ft_parsenumber(t_buff *buff, t_ulong *nb);
t_bool			ft_parsedouble(t_buff *buff, double *nb);

t_bool			ft_parse(t_buff *buff, const char *parse);
t_bool			ft_parsenot(t_buff *buff, const char *parse);
t_bool			ft_parsestr(t_buff *buff, const char *str);

void			ft_parseendl(t_buff *buff);
t_bool			ft_parsen(t_buff *buff, char *dst, int len);

t_bool			ft_parsef(t_buff *buff, t_bool (*f)(int c));
t_bool			ft_parsespace(t_buff *buff);
t_bool			ft_parsewhite(t_buff *buff);

/*
** ========================================================================== **
** Use the struct s_out (t_out) to write to a fd
** ----
** Constructors:
**  OUT (fd, buff, buff_size)	Create a file out
**  DSTR_OUT (dstr)				Create a dynamic string (ft_dstr) out
**  BUFF_OUT (buff, buff_size)	Create a static (circular) buffer out
*/

# define OUT_NOFLUSH	(1 << 1)
# define OUT_DSTR		(1 << 2)

# define OUT(f,b,l)		((t_out){(b), 0, (l), (f), 0})
# define DSTR_OUT(d)	((t_out){(char*)(d), 0, 0, -1, OUT_DSTR})
# define BUFF_OUT(b,l)	((t_out){(b), 0, (l), -1, OUT_NOFLUSH})

typedef struct	s_out
{
	char			*buff;
	int				i;
	int				length;
	int				fd;
	int				flags;
}				t_out;

void			ft_write(t_out *out, const char *data, t_uint len);
void			ft_writestr(t_out *out, const char *str);
void			ft_writechar(t_out *out, char c);
void			ft_writenchar(t_out *out, char c, int n);
void			ft_writenl(t_out *out);
void			ft_writeint(t_out *out, int n);
void			ft_writebase(t_out *out, t_ulong n, const char *base);
void			ft_writedouble(t_out *out, double d, int preci);
int				ft_flush(t_out *out);

/*
** ========================================================================== **
** static t_out FTOUT
*/

extern t_out	g_ftout;

# define DEF_PRECI		7

# define FTOUT			(&g_ftout)

# define P(f, ...)		(ft_writef(FTOUT, (f), __VA_ARGS__))
# define PS(s)			(ft_writestr(FTOUT, (s)))
# define PC(c)			(ft_writechar(FTOUT, (c)))
# define PCN(c,n)		(ft_writenchar(FTOUT, (c), (n)))
# define PI(i)			(ft_writeint(FTOUT, (i)))
# define PB(i,b)		(ft_writebase(FTOUT, (i), (b)))
# define PF(f)			(ft_writedouble(FTOUT, (f), DEF_PRECI))
# define PFP(f,p)		(ft_writedouble(FTOUT, (f), (p)))
# define NL				(ft_writenl(FTOUT))
# define FL				(ft_flush(FTOUT))

void			ft_out(int fd);

void			ft_hexdump(const void *data, t_uint len);

/*
** ========================================================================== **
** Math
*/

# define MIN(a,b)		(((a) < (b)) ? (a) : (b))
# define MAX(a,b)		(((a) > (b)) ? (a) : (b))
# define ABS(a)			(((a) < 0) ? -(a) : (a))

# define UP(n)			((int)(1 + (n)))
# define ROUND(n)		((int)(0.5 + (n)))
# define DOWN(n)		((int)(n))

# define PT(x,y)		((t_pt){(x), (y)})
# define POS(x,y,z)		((t_pos){(x), (y), (z)})
# define RECT(x,y,w,h)	((t_rect){(x), (y), (w), (h)})

# define BIG(a)			((a) * 1000000)
# define BTOI(a)		((a) / 1000000)
# define MIX(a,b,p)		((a) - BTOI((a) * (p)) + BTOI((b) * (p)))

# define ISNAN(d)		((d) != (d))

typedef struct	s_pos
{
	double			x;
	double			y;
	double			z;
}				t_pos;

typedef struct	s_pt
{
	int				x;
	int				y;
}				t_pt;

typedef struct	s_rect
{
	int				x;
	int				y;
	int				width;
	int				height;
}				t_rect;

int				ft_mix(int a, int b, t_big pos);

int				ft_abs(int a);
int				ft_max(int a, int b);
int				ft_min(int a, int b);

void			ft_resrect(t_rect *rect, t_rect bounds);

int				ft_dist2(t_pt p1, t_pt p2);

t_pt			ft_nearest(t_pt pos, t_pt p1, t_pt p2);
t_pt			ft_farthest(t_pt pos, t_pt p1, t_pt p2);

/*
** ========================================================================== **
** Draw
*/

# define C(c)			((t_color)(t_uint)(c))
# define RGBA(r,g,b,a)	((t_color)((t_rgb){(b), (g), (r), (a)}))
# define RGB(r,g,b)		RGBA(r, g, b, 0)
# define INVI(c)		((c).u > 0xFF000000)
# define ALPHA(c)		((c).u >= 0x01000000)

# define IMAGEPOS(i,p)	*((t_color*)((void*)((i)->data + (p))))
# define IMAGEPT(i,x,y)	IMAGEPOS(i, ((i)->width * y + x) * (i)->opp)

typedef struct	s_image
{
	t_byte			*data;
	void			*img;
	int				width;
	int				height;
	int				l_size;
	int				opp;
	int				endian;
}				t_image;

typedef struct	s_rgb
{
	t_uchar			b;
	t_uchar			g;
	t_uchar			r;
	t_uchar			a;
}				t_rgb;

typedef union	u_color
{
	t_rgb			b;
	t_uint			u;
	int				i;
	t_uchar			t[4];
}				t_color;

void			ft_resalpha(t_color *c, t_color bg);

void			ft_imageclr(t_image *img);
void			ft_imageclrc(t_image *img, t_color color);
t_image			*ft_imageclone(t_image *img);
void			ft_imageclonekil(t_image *clone);

void			ft_drawxy(t_image *img, int x, int y, t_color color);
void			ft_drawpt(t_image *img, t_pt pt, t_color color);
void			ft_drawnpt(t_image *img, t_pt pt, int n, t_color color);
void			ft_drawvert(t_image *img, t_pt pt, int height, t_color color);

void			ft_drawimage(t_image *dst, t_image *src, t_pt pos, t_rect part);

void			ft_drawline(t_image *img, t_pt p1, t_pt p2, t_color color);
void			ft_drawrect(t_image *img, t_rect rect, t_color color);
void			ft_drawrectf(t_image *img, t_rect rect, t_color color);
void			ft_drawdiv(t_image *img, int y, int height, t_color color);
void			ft_drawcircle(t_image *img, t_pt o, int radius, t_color color);
void			ft_drawcirclef(t_image *img, t_pt o, int radius, t_color color);
void			ft_drawtri(t_image *img, t_pt pts[3], t_color color);
void			ft_drawtrif(t_image *img, t_pt pts[3], t_color color);

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

# ifdef DEBUG_MODE
#  define TRACE			ft_printf("%s %s:%d\n", __func__, __FILE__, __LINE__)
# else
#  define TRACE
# endif

int				ft_printf(const char *format, ...);
int				ft_fdprintf(const int fd, const char *format, ...);
int				ft_sprintf(char *dst, char const *format, ...);
int				ft_snprintf(char *dst, int max_len, char const *format, ...);
int				ft_writef(t_out *out, const char *format, ...);

/*
** ========================================================================== **
*/

#endif
