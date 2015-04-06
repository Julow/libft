/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:52:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/06 17:46:53 by jaguillo         ###   ########.fr       */
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
** EMAL_ALL
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

# define IGNORE(f)		((void)((f) + 1))

# define DB(l,v)		{[0 ... ((l) - 1)] = (v)}

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

/*
** ========================================================================== **
** Memory
*/

# define EMAL(t,l)		((t*)ft_emalloc(sizeof(t) * (l)))
# define EMAL1(t)		((t*)ft_emalloc(sizeof(t)))

# ifdef EMAL_ALL
#  define MAL			EMAL
#  define MAL1			EMAL1
# else
#  define MAL(t,l)		((t*)malloc(sizeof(t) * (l)))
#  define MAL1(t)		((t*)malloc(sizeof(t)))
# endif

# define S(t,l)			(sizeof(t) * (l))

void			*ft_bzero(void *mem, t_uint len);
void			*ft_emalloc(t_uint size);
void			*ft_memset(void *mem, int c, t_uint len);
void			*ft_memcpy(void *dst, const void *src, t_uint len);
void			*ft_memrcpy(void *dst, const void *src, t_uint len);
void			*ft_memccpy(void *dst, const void *src, int c, t_uint n);
void			*ft_memmove(void *dst, const void *src, t_uint len);
void			*ft_memdup(const void *src, t_uint len);
void			ft_memswap(void *mem1, void *mem2, t_uint len);
void			*ft_memchr(const void *s, int c, t_uint n);
int				ft_memcmp(const void *mem1, const void *mem2, t_uint len);
void			*ft_memalloc(t_uint size);
void			ft_memralloc(void **mem, t_uint len, t_uint newlen);
void			ft_memdel(void **ap);

t_uint			ft_tablen(void **array);

/*
** ========================================================================== **
** String
*/

# define SUB(s,l)		((t_sub){(s), (l)})

typedef struct	s_sub
{
	char			*str;
	int				length;
}				t_sub;

char			*ft_strnew(t_uint size);
t_uint			ft_strlen(const char *str);
char			*ft_strdup(const char *str);
char			*ft_strndup(const char *src, t_uint len);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, t_uint len);
char			*ft_strsub(const char *s, t_uint start, t_uint len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(const char *s);
char			**ft_strsplit(const char *s, char c);

int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, t_uint n);
t_bool			ft_strequ(const char *s1, const char *s2);
t_bool			ft_strnequ(const char *s1, const char *s2, t_uint n);
t_bool			ft_strcase(const char *s1, const char *s2);
t_bool			ft_strncase(const char *s1, const char *s2, t_uint n);

void			ft_strnadd(char **str, const char *add, t_uint len);

/*
** ========================================================================== **
** String search
*/

char			*ft_strchr(const char *s, char c);
char			*ft_strnchr(const char *s, char c, int len);
int				ft_strchri(const char *str, char c);
int				ft_strichri(const char *str, char c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, t_uint n);

t_uint			ft_strskip(const char *str, const char *skip);
t_uint			ft_strcskip(const char *str, const char *skip);
t_uint			ft_strskipe(const char *str, const char *skip);
t_uint			ft_strcskipe(const char *str, const char *skip);

char			*ft_strstart(char *str, const char *start);

int				ft_strbrace(const char *str, char open, char close);

/*
** ========================================================================== **
** String test
*/

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

/*
** ========================================================================== **
** String - Useless
*/
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, t_uint n);
t_uint			ft_strlcat(char *dst, const char *src, t_uint size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(int, char*));
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(int, char));

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

char			*ft_itoa(int n);
char			*ft_ltoa(t_long n);

char			*ft_itobase(t_ulong nb, const char *base);
t_ulong			ft_basetoi(const char *str, const char *base);

char			ft_escape(char c);
char			ft_unescape(char c);

int				ft_toupper(int c);
int				ft_tolower(int c);
void			ft_strlower(char *str);
void			ft_strupper(char *str);

/*
** ========================================================================== **
** W String
*/

t_uint			ft_wstrlen(int *wstr);
int				ft_wstrconv(char *buff, int *wstr);
int				ft_wstrnconv(char *buff, int *wstr, int n);
int				ft_widetoa(char *buff, int w);

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

char			*ft_getenv(const char *key);

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
** Try/Catch
*/

# define TRY(t)			if (ft_try(t) == 0)
# define CATCH			else

int				ft_try(void *t);
void			ft_throw(void *t);

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
** Store mem using the struct s_list (t_list)
*/

typedef struct	s_list
{
	void			*content;
	t_uint			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(const void *content, t_uint content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, t_uint));
void			ft_lstdelnext(t_list *lst, void (*f)(void*, t_uint));
void			ft_lstdel(t_list **alst, void (*del)(void*, t_uint));
void			ft_lstadd(t_list **alst, t_list *add);
void			ft_lstafter(t_list *lst, t_list *add);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** ========================================================================== **
** Store mem using the struct s_tab (t_tab)
*/

# define TI(b,i)		(((t_tab*)(b))->data + (((t_tab*)(b))->size * (i)))
# define TG(t,b,i)		((t*)TI(&(b), (i)))

typedef struct	s_tab
{
	t_byte			*data;
	int				length;
	int				bytes;
	int				alloc_bytes;
	int				size;
}				t_tab;

t_tab			*ft_tabnew(int size);
void			ft_tabini(t_tab *tab, int size);
void			*ft_tabget(t_tab *tab, int index);
void			*ft_tabadd0(t_tab *tab);
void			ft_tabadd(t_tab *tab, const void *add);
void			ft_tabaddn(t_tab *tab, const void *add, int n);
void			ft_tabset(t_tab *tab, const void *set, int index, int n);
void			ft_tabins(t_tab *tab, const void *ins, int index, int n);
void			ft_tabrem(t_tab *tab, int index, int n);
void			ft_tabrot(t_tab *tab, int rot);
void			ft_tabpop(t_tab *tab);
int				ft_tabchr(t_tab *tab, const void *chr);
void			ft_tabfree(t_tab *tab);
void			ft_tabclr(t_tab *tab);
void			ft_tabkil(void *tab);
void			ft_tabswap(t_tab *tab, int i1, int i2);
void			ft_tabrev(t_tab *tab);
t_bool			ft_tabext(t_tab *tab, int need);

/*
** ========================================================================== **
** Store pointers using the struct s_array (t_array)
** Allocate memory by block of 16 to reduce the number of free/malloc/copy
*/

# define AG(t,a,i)		((t)(((t_array*)(a))->data[i]))

typedef struct	s_array
{
	void			**data;
	int				length;
	int				alloc_length;
}				t_array;

t_array			*ft_arraynew(void);
void			ft_arrayini(t_array *array);
void			ft_arrayadd(t_array *array, void *add);
void			ft_arrayset(t_array *array, void *set, int index);
void			ft_arrayins(t_array *array, void *ins, int index);
void			*ft_arrayrem(t_array *array, int index);
void			*ft_arraypop(t_array *array);
int				ft_arraychr(t_array *array, const void *chr);
void			ft_arrayapp(t_array *array, const t_array *app);
t_array			*ft_arraydup(const t_array *array);
void			ft_arrayfree(t_array *array);
void			ft_arrayclr(void *array, void (*f)(void *data));
void			ft_arraykil(void *array, void (*f)(void *data));
void			ft_arraykilf(void *array);
void			ft_arrayswap(t_array *array, int i1, int i2);
void			ft_arrayrev(t_array *array);
t_bool			ft_arrayext(t_array *array, int need);

/*
** ========================================================================== **
** Manipulate string using the struct s_string (t_string)
** Allocate memory by block of 16 to reduce the number of free/malloc/copy
*/

typedef struct	s_string
{
	char			*content;
	int				length;
	int				alloc_length;
}				t_string;

t_string		*ft_stringnew(void);
t_string		*ft_stringnews(const char *s);
void			ft_stringini(t_string *str);
void			ft_stringaddc(t_string *str, char c);
void			ft_stringadd(t_string *str, const char *add);
void			ft_stringaddi(t_string *str, int nbr);
void			ft_stringaddil(t_string *str, t_long nbr);
void			ft_stringaddid(t_string *str, double nbr);
void			ft_stringaddd(t_string *str, double d, int preci);
void			ft_stringaddde(t_string *str, double d, int preci);
void			ft_stringaddl(t_string *str, const char *add, int len);
void			ft_stringaddcn(t_string *str, char c, int n);
void			ft_stringsetc(t_string *str, char c, int index);
void			ft_stringset(t_string *str, const char *set, int index);
void			ft_stringsetl(t_string *str, const char *set, int index, int l);
void			ft_stringinsc(t_string *str, char c, int index);
void			ft_stringins(t_string *str, const char *ins, int index);
void			ft_stringinsl(t_string *str, const char *ins, int index, int l);
void			ft_stringrepc(t_string *str, char c, char r);
void			ft_stringrep(t_string *str, const char *chr, const char *rep);
t_string		*ft_stringdup(t_string *str);
t_string		*ft_stringsub(t_string *str, int index, int len);
void			ft_stringrem(t_string *str, int index, int len);
void			ft_stringtrim(t_string *str);
void			ft_stringtrimc(t_string *str, const char *trim);
t_array			*ft_stringsplit(t_string *str, const char *chr);
t_array			*ft_stringsplitc(t_string *str, char c);
int				ft_stringchr(t_string *str, char c);
int				ft_stringstr(t_string *str, const char *chr, int start);
void			ft_stringfree(t_string *str);
void			ft_stringclr(t_string *str);
void			ft_stringkil(void *str);
t_bool			ft_stringext(t_string *str, int need);
int				ft_stringput(t_string *str);
int				ft_stringputfd(t_string *str, int const fd);

/*
** ========================================================================== **
** Store pointers paired with a t_string 'key'
** Use with the struct s_array (t_array)
*/

typedef struct	s_pair
{
	t_string		*key;
	void			*value;
}				t_pair;

t_pair			*ft_pairnew(const char *key, void *value);
t_pair			*ft_pairget(t_array *array, const char *key);
int				ft_pairchr(t_array *array, const char *key);
t_pair			*ft_pairrem(t_array *array, const char *key);
void			ft_pairsort(t_array *array);

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

# define BEOF(b)		FLAG((b)->fd, BF_EOF)
# define BSTR(b)		FLAG((b)->fd, BF_STR)
# define BFD(b)			((b)->fd & 0xFF)

# define BUFF(f,b,l)	((t_buff){(b), 0, 0, (l), (f) & 0xFF})
# define SBUFF(s,l)		((t_buff){(s), 0, (l), (l), -1 & 0xFF | BF_STR})

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

int				ft_parsesub(t_buff *buff, t_string *dst, const char *parse);
int				ft_parsesubf(t_buff *buff, t_string *dst, t_bool (*f)(int c));
int				ft_parsesubnf(t_buff *buff, t_string *dst, t_bool (*f)(int c));
int				ft_parseline(t_buff *buff, t_string *dst);
t_bool			ft_parsequote(t_buff *buff, t_string *dst);

void			ft_parseendl(t_buff *buff);
t_bool			ft_parsen(t_buff *buff, char *dst, int len);

t_bool			ft_parsef(t_buff *buff, t_bool (*f)(int c));
t_bool			ft_parsespace(t_buff *buff);
t_bool			ft_parsewhite(t_buff *buff);

/*
** ========================================================================== **
** Use the struct s_out (t_out) to write to a fd
*/

# define OUT(f,b,l)		((t_out){(b), 0, (l), (f)})

typedef struct	s_out
{
	char			*buff;
	int				i;
	int				length;
	int				fd;
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
int				ft_writef(t_out *out, const char *format, ...);

/*
** ========================================================================== **
*/

#endif
