/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:52:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/12 22:35:43 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define MAL(t,l)		((t*)malloc(sizeof(t) * (l)))
# define MAL1(t)		((t*)malloc(sizeof(t)))

# define S(t,l)			(sizeof(t) * (l))

# define TG(t,b,i)		(*(t*)(((t_tab*)b)->data + (((t_tab*)b)->size * (i))))
# define TI(b,i)		(((t_tab*)b)->data + (((t_tab*)b)->size * (i)))
# define AG(t,a,i)		((t)(((t_array*)(a))->data[i]))

# define B(b)			((b)->data[(b)->i])
# define BUFF(s,i,l)	((t_buff){(s), (i), (l), -1})
# define FBUFF(fd)		((t_buff){MAL(char, BUFF_SIZE), 0, 0, fd})

# define MIN(a,b)		(((a) < (b)) ? (a) : (b))
# define MAX(a,b)		(((a) > (b)) ? (a) : (b))
# define ABS(a)			(((a) < 0) ? -(a) : (a))

# define UP(n)			((int)(1 + (n)))
# define ROUND(n)		((int)(0.5 + (n)))
# define DOWN(n)		((int)(n))

# define PT(x,y)		((t_pt){(x), (y)})
# define POS(x,y,z)		((t_pos){(x), (y), (z)})
# define RECT(x,y,w,h)	((t_rect){(x), (y), (w), (h)})

# define C(c)			((t_color)(t_uint)(c))
# define RGBA(r,g,b,a)	((t_rgb){(b), (g), (r), (a)})
# define RGB(r,g,b)		RGBA(r, g, b, 255)
# define INVI(c)		((c).u < 0x01000000)
# define ALPHA(c)		((c).u < 0xFF000000)

# define BIG(a)			((a) * 1000000)
# define BTOI(a)		((a) / 1000000)
# define MIX(a,b,p)		((a) - BTOI((a) * (p)) + BTOI((b) * (p)))

# define IGNORE(f)		((void)((f) + 1))

# define ISNAN(d)		((d) != (d))

# ifdef DEBUG_MODE
#  define DEBUG(d, ...) ft_debug(__func__, __FILE__, __LINE__, d, __VA_ARGS__)
#  define TRACE			ft_debug(__func__, __FILE__, __LINE__, NULL)
# else
#  define DEBUG(d, ...)
#  define TRACE
# endif

# ifndef TRUE
#  define TRUE			1
# endif
# ifndef FALSE
#  define FALSE			0
# endif

# ifndef NULL
#  define NULL			((void*)0)
# endif

# ifndef ERROR
#  define ERROR			-1
# endif

# ifndef EOF
#  define EOF			-1
# endif

# define FTUCHAR		unsigned char
# define FTUINT			unsigned int
# define FTLONG			long long int
# define FTULONG		unsigned long long int

/*
** t_big represent a decimal number
** it's a t_long divide by 1000000
** ==> 9 223 372 000 000.000 000
*/
typedef FTLONG	t_big;

typedef char	t_bool;
typedef FTUCHAR	t_byte;
typedef FTUCHAR	t_uchar;
typedef FTUINT	t_uint;
typedef FTLONG	t_long;
typedef FTULONG	t_ulong;

# undef FTUCHAR
# undef FTUINT
# undef FTLONG
# undef FTULONG

typedef struct	s_list
{
	void			*content;
	t_uint			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_array
{
	void			**data;
	int				length;
	int				alloc_length;
}				t_array;

typedef struct	s_tab
{
	t_byte			*data;
	int				length;
	int				bytes;
	int				alloc_bytes;
	int				size;
}				t_tab;

typedef struct	s_string
{
	char			*content;
	int				length;
	int				alloc_length;
}				t_string;

typedef struct	s_pair
{
	t_string		*key;
	void			*value;
}				t_pair;

typedef struct	s_buff
{
	char			*data;
	int				i;
	int				length;
	int				fd;
}				t_buff;

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
}				t_color;

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

typedef struct	s_pos
{
	double			x;
	double			y;
	double			z;
}				t_pos;

/*
** Memory
*/
inline void		ft_bzero(void *s, t_uint n);
t_ulong			*ft_memalign(void *mem, const void *data, t_uint *len);
void			*ft_memset(void *b, int c, t_uint len);
void			*ft_memcpy(void *dst, const void *src, t_uint len);
void			*ft_memccpy(void *dst, const void *src, int c, t_uint n);
void			*ft_memmove(void *dst, const void *src, t_uint len);
void			*ft_memdup(const void *src, t_uint len);
void			ft_memswap(void *mem1, void *mem2, t_uint len);
void			*ft_memchr(const void *s, int c, t_uint n);
int				ft_memcmp(const void *s1, const void *s2, t_uint n);
void			*ft_memalloc(t_uint size);
void			ft_memralloc(void **mem, t_uint len, t_uint newlen);
void			ft_memdel(void **ap);

t_uint			ft_tablen(void **array);

/*
** String
*/
char			*ft_strnew(t_uint size);
inline t_uint	ft_strlen(const char *str);
char			*ft_strdup(const char *src);
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

inline t_bool	ft_isalpha(char c);
inline t_bool	ft_isdigit(char c);
inline t_bool	ft_isalnum(char c);
inline t_bool	ft_isascii(int c);
inline t_bool	ft_isprint(char c);
inline t_bool	ft_isspace(char c);
inline t_bool	ft_iswhite(char c);

t_bool			ft_isato(const char *str);
t_bool			ft_isnumber(const char *str);

/*
** String search
*/
char			*ft_strchr(const char *s, char c);
char			*ft_strnchr(const char *s, char c, int len);
int				ft_strchri(const char *str, char c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, t_uint n);

t_uint			ft_strskip(const char *str, const char *skip);
t_uint			ft_strcskip(const char *str, const char *skip);
t_uint			ft_strskipe(const char *str, const char *skip);
t_uint			ft_strcskipe(const char *str, const char *skip);

t_bool			ft_match(char *str, char *pattern);
int				ft_nmatch(char *str, char *pattern);
t_bool			ft_hidenp(char *hide, char *str);

/*
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
** Conversion
*/
int				ft_atoi(const char *str);
t_long			ft_atol(const char *str);
double			ft_atod(const char *str);

char			*ft_itoa(int n);
char			*ft_ltoa(t_long n);

char			*ft_itobase(t_ulong nb, const char *base);
t_ulong			ft_basetoi(const char *str, const char *base);

inline int		ft_toupper(int c);
inline int		ft_tolower(int c);
void			ft_strlower(char *str);
void			ft_strupper(char *str);

int				ft_wstrconv(char *buff, int *wstr);
int				ft_wstrnconv(char *buff, int *wstr, int n);
int				ft_widetoa(char *buff, int w);

/*
** Write
*/
inline int		ft_putchar(char c);
inline int		ft_putnchar(char c, int n);
inline int		ft_putstr(const char *s);
inline int		ft_putlstr(const char *s, int len);
inline int		ft_putendl(const char *s);
inline int		ft_putnbr(int n);
inline int		ft_putlong(t_long n);
inline int		ft_putchar_fd(char c, int fd);
int				ft_putnchar_fd(char c, int n, int fd);
inline int		ft_putstr_fd(const char *s, int fd);
inline int		ft_putlstr_fd(const char *s, int len, int fd);
inline int		ft_putendl_fd(const char *s, int fd);
int				ft_putnbr_fd(int n, int fd);
int				ft_putlong_fd(t_long n, int fd);

/*
** Store mem using the struct s_list (t_list)
*/
t_list			*ft_lstnew(const void *content, t_uint content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, t_uint));
void			ft_lstdelnext(t_list *lst, void (*f)(void*, t_uint));
void			ft_lstdel(t_list **alst, void (*del)(void*, t_uint));
void			ft_lstadd(t_list **alst, t_list *add);
void			ft_lstafter(t_list *lst, t_list *add);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** Store mem using the struct s_tab (t_tab)
*/
t_tab			*ft_tabnew(int size);
void			ft_tabini(t_tab *tab, int size);
inline void		*ft_tabget(t_tab *tab, int index);
void			*ft_tabadd0(t_tab *tab);
inline void		ft_tabadd(t_tab *tab, const void *add);
inline void		ft_tabaddn(t_tab *tab, const void *add, int n);
void			ft_tabset(t_tab *tab, const void *set, int index, int n);
void			ft_tabins(t_tab *tab, const void *ins, int index, int n);
void			ft_tabrem(t_tab *tab, int index, int n);
inline void		ft_tabpop(t_tab *tab);
int				ft_tabchr(t_tab *tab, const void *chr);
void			ft_tabfree(t_tab *tab);
void			ft_tabclr(t_tab *tab);
void			ft_tabkil(void *tab);
void			ft_tabswap(t_tab *tab, int i1, int i2);
void			ft_tabrev(t_tab *tab);
t_bool			ft_tabext(t_tab *tab, int need);

/*
** Store pointers using the struct s_array (t_array)
** Allocate memory by block of 16 to reduce the number of free/malloc/copy
*/
t_array			*ft_arraynew(void);
void			ft_arrayini(t_array *array);
inline void		ft_arrayadd(t_array *array, void *add);
void			ft_arrayset(t_array *array, void *set, int index);
void			ft_arrayins(t_array *array, void *ins, int index);
void			*ft_arrayrem(t_array *array, int index);
inline void		*ft_arraypop(t_array *array);
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
** Store pointers paired with a t_string 'key'
** Use with the struct s_array (t_array)
*/
t_pair			*ft_pairnew(const char *key, void *value);
t_pair			*ft_pairget(t_array *array, const char *key);
int				ft_pairchr(t_array *array, const char *key);
t_pair			*ft_pairrem(t_array *array, const char *key);
void			ft_pairsort(t_array *array);

/*
** Manipulate string using the struct s_string (t_string)
** Allocate memory by block of 16 to reduce the number of free/malloc/copy
*/
t_string		*ft_stringnew(void);
t_string		*ft_stringnews(const char *s);
void			ft_stringini(t_string *str);
inline void		ft_stringaddc(t_string *str, char c);
inline void		ft_stringadd(t_string *str, const char *add);
void			ft_stringaddi(t_string *str, int nbr);
void			ft_stringaddil(t_string *str, t_long nbr);
void			ft_stringaddid(t_string *str, double nbr);
void			ft_stringaddd(t_string *str, double d, int preci);
void			ft_stringaddde(t_string *str, double d, int preci);
inline void		ft_stringaddl(t_string *str, const char *add, int len);
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
** struct s_buff (t_buff) represent a buffer being parsed
** 'data' may not be NULL terminated
** == string buff ('fd' < 0)
** 'data' is not the original malloced pointer (can't be free)
** macro B() return the current char
** macro BUFF() init a t_buff
** == file buff ('fd' >= 0)
** 'data' need to be the original malloced pointer (automaticaly free)
** macro FBUFF() init a file t_buff (malloc 'data')
*/
inline char		ft_readbuff(t_buff *buff);
inline char		ft_buffget(t_buff *buff);
void			ft_parse(t_buff *buff, const char *parse);
void			ft_parsenot(t_buff *buff, const char *parse);
t_string		ft_parsesub(t_buff *buff, const char *parse);
t_string		ft_parseline(t_buff *buff);
int				ft_parseint(t_buff *buff);
t_long			ft_parselong(t_buff *buff);
void			ft_parsespace(t_buff *buff);

/*
** Work only for string buff
*/
double			ft_parsedouble(t_buff *buff);
t_bool			ft_parsestr(t_buff *buff, const char *str);

/*
** Math
*/
inline int		ft_mix(int a, int b, t_big pos);
inline int		ft_max(int a, int b);

inline void		ft_resalpha(t_color *c, t_color bg);
inline void		ft_resrect(t_rect *rect, t_rect bounds);

/*
** Draw on struct s_image (t_image)
*/
inline t_color	ft_imagept(t_image *img, t_pt pt);
inline t_color	ft_imagepos(t_image *img, int pos);
inline void		ft_imageput(t_image *img, int pos, t_color color);
void			ft_imageclr(t_image *img);
void			ft_imageclrc(t_image *img, t_color color);
t_image			*ft_imageclone(t_image *img);
void			ft_imageclonekil(t_image *clone);

inline void		ft_drawxy(t_image *img, int x, int y, t_color color);
inline void		ft_drawpt(t_image *img, t_pt pt, t_color color);
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
** get_next_line
*/
int				get_next_line(int const fd, t_buff *line);

/*
** =============
** A format sequence be like:
**    %[flags][width][.precision]format
** flags can be 0 or more: '#', ' ', '-', '+', '^', '0', ''', '>', 'm', 'M', 'T'
** width is a positive integer
** precision is a positive integer or '*', precision start with '.'
** format can be one of "%sSdDoOuUxXicCnp"
** =============
** =
** =
** ft_printf
** =============
** Process the format sequence like printf and print the result to stdout
** =============
** Return the total of char printed.
** =
** =
** ft_printf_fd
** =============
** Like ft_printf but the result is printed to the fd 'fd'
** =============
** Return the total of char printed.
** =
** =
** ft_stringf
** =============
** Like ft_printf but the result return in a t_string
** =============
** A t_string containing the result.
*/
int				ft_printf(const char *format, ...);
int				ft_fdprintf(const int fd, const char *format, ...);
t_string		*ft_stringf(const char *format, ...);
void			ft_debug(const char *c, char *f, int l, const char *s, ...);

#endif
