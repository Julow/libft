/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:52:52 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/03 11:52:56 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

# define MAL(t,l)		((t*)ft_malloc(sizeof(t) * (l)))
# define MAL1(t)		((t*)ft_malloc(sizeof(t)))

# define VOIDADD(p,n)	((void*)(((t_byte*)(p)) + (n)))
# define VOIDPP(p)		((p) = (void*)(((t_byte*)(p)) + 1))
# define VOIDMM(p)		((p) = (void*)(((t_byte*)(p)) - 1))

# define TG(t,b,i)		(*(t*)(((t_tab*)b)->data + (((t_tab*)b)->size * (i))))
# define TI(b,i)		(((t_tab*)b)->data + (((t_tab*)b)->size * (i)))
# define AG(t,a,i)		((t)(((t_array*)(a))->data[i]))

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

# ifndef TRUE
#  define TRUE			1
# endif
# ifndef FALSE
#  define FALSE			0
# endif

# ifndef ERROR
#  define ERROR			-1
# endif

# ifndef EOF
#  define EOF			-1
# endif

# define UCHAR			unsigned char
# define UINT			unsigned int
# define LONG			long long int
# define ULONG			unsigned long long int

/*
** t_big represent a decimal number
** it's a t_long divide by 1000000
** ==> 9 223 372 000 000.000 000
*/
typedef LONG	t_big;

typedef char	t_bool;
typedef UCHAR	t_byte;
typedef UCHAR	t_uchar;
typedef UINT	t_uint;
typedef LONG	t_long;
typedef ULONG	t_ulong;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
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
void			*ft_malloc(size_t size);

void			ft_bzero(void *s, size_t n);
t_ulong			*ft_memalign(void *mem, const void *data, size_t *len);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t len);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			ft_memswap(void *mem1, void *mem2, t_uint len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memralloc(void **mem, t_uint len, t_uint newlen);
void			ft_memdel(void **ap);

size_t			ft_tablen(void **array);

/*
** String
*/
char			*ft_strnew(size_t size);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *src);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);

int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);

void			ft_strnadd(char **str, char const *add, size_t len);

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_iswhite(int c);

t_bool			ft_isato(const char *str);
t_bool			ft_isnumber(const char *str);

/*
** String search
*/
char			*ft_strchr(const char *s, int c);
int				ft_strchri(char *str, char c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);

t_bool			ft_match(char *str, char *pattern);
int				ft_nmatch(char *str, char *pattern);
t_bool			ft_hidenp(char *hide, char *str);

/*
** String - Useless
*/
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
** Conversion
*/
int				ft_atoi(const char *str);
t_long			ft_atol(const char *str);
double			ft_atod(const char *str);

char			*ft_itoa(int n);
char			*ft_ltoa(t_long n);

char			*ft_itobase(t_long nb, char *base);
t_long			ft_basetoi(char *str, char *base);

int				ft_toupper(int c);
int				ft_tolower(int c);
void			ft_strlower(char *str);
void			ft_strupper(char *str);

/*
** Write
*/
void			ft_putchar(char c);
void			ft_putnchar(char c, int n);
void			ft_putstr(char const *s);
void			ft_putlstr(char const *s, int len);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putnchar_fd(char c, int n, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putlstr_fd(char const *s, int len, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
** Store mem using the struct s_list (t_list)
*/
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdelnext(t_list *lst, void (*f)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstafter(t_list *lst, t_list *add);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** Store mem using the struct s_tab (t_tab)
*/
t_tab			*ft_tabnew(int size);
void			ft_tabini(t_tab *tab, int size);
void			*ft_tabget(t_tab *tab, int index);
void			*ft_tabadd0(t_tab *tab);
void			ft_tabadd(t_tab *tab, void *add);
void			ft_tabaddn(t_tab *tab, void *add, int n);
void			ft_tabset(t_tab *tab, void *set, int index, int n);
void			ft_tabins(t_tab *tab, void *ins, int index, int n);
void			ft_tabrem(t_tab *tab, int index, int n);
void			ft_tabpop(t_tab *tab);
int				ft_tabchr(t_tab *tab, void *chr);
void			ft_tabfree(t_tab *tab);
void			ft_tabclr(t_tab *tab);
void			ft_tabkil(void *tab);
void			ft_tabswap(t_tab *tab, int i1, int i2);
void			ft_tabrev(t_tab *tab);
void			ft_tabext(t_tab *tab, int need);

/*
** Store pointers using the struct s_array (t_array)
** Allocate memory by block of 16 to reduce the number of free/malloc/copy
*/
t_array			*ft_arraynew(void);
void			ft_arrayini(t_array *array);
void			ft_arrayadd(t_array *array, void *add);
void			ft_arrayset(t_array *array, void *set, int index);
void			ft_arrayins(t_array *array, void *ins, int index);
void			*ft_arrayrem(t_array *array, int index);
void			*ft_arraypop(t_array *array);
int				ft_arraychr(t_array *array, void *chr);
void			ft_arrayapp(t_array *array, t_array *app);
void			ft_arrayfree(t_array *array);
void			ft_arrayclr(void *array, void (*f)(void *data));
void			ft_arraykil(void *array, void (*f)(void *data));
void			ft_arraykilf(void *array);
void			ft_arrayswap(t_array *array, int i1, int i2);
void			ft_arrayrev(t_array *array);
void			ft_arrayext(t_array *array, int need);

/*
** Store pointers paired with a t_string 'key'
** Use with the struct s_array (t_array)
*/
t_pair			*ft_pairnew(char *key, void *value);
t_pair			*ft_pairget(t_array *array, char *key);
int				ft_pairchr(t_array *array, char *key);
t_pair			*ft_pairrem(t_array *array, char *key);
void			ft_pairsort(t_array *array);

/*
** Manipulate string using the struct s_string (t_string)
** Allocate memory by block of 16 to reduce the number of free/malloc/copy
*/
t_string		*ft_stringnew(void);
t_string		*ft_stringnews(char *s);
void			ft_stringini(t_string *str);
void			ft_stringaddc(t_string *str, char c);
void			ft_stringadd(t_string *str, char *add);
void			ft_stringaddi(t_string *str, int nbr);
void			ft_stringaddil(t_string *str, t_long nbr);
void			ft_stringaddid(t_string *str, double nbr);
void			ft_stringaddd(t_string *str, double d, int preci);
void			ft_stringaddde(t_string *str, double d, int preci);
void			ft_stringaddl(t_string *str, char *add, int len);
void			ft_stringaddcn(t_string *str, char c, int n);
void			ft_stringsetc(t_string *str, char c, int index);
void			ft_stringset(t_string *str, char *set, int index);
void			ft_stringsetl(t_string *str, char *set, int index, int len);
void			ft_stringinsc(t_string *str, char c, int index);
void			ft_stringins(t_string *str, char *ins, int index);
void			ft_stringinsl(t_string *str, char *ins, int index, int len);
void			ft_stringrepc(t_string *str, char c, char r);
void			ft_stringrep(t_string *str, char *chr, char *rep);
t_string		*ft_stringdup(t_string *str);
t_string		*ft_stringsub(t_string *str, int index, int len);
void			ft_stringrem(t_string *str, int index, int len);
void			ft_stringtrim(t_string *str);
void			ft_stringtrimc(t_string *str, char *trim);
t_array			*ft_stringsplit(t_string *str, char *chr);
t_array			*ft_stringsplitc(t_string *str, char c);
int				ft_stringchr(t_string *str, char c);
int				ft_stringstr(t_string *str, char *chr, int start);
void			ft_stringfree(t_string *str);
void			ft_stringclr(t_string *str);
void			ft_stringkil(void *str);
void			ft_stringext(t_string *str, int need);
int				ft_stringput(t_string *str);
int				ft_stringputfd(t_string *str, int const fd);

/*
** Math
*/
int				ft_mix(int a, int b, t_big pos);

/*
** Draw on struct s_image (t_image)
*/
void			ft_resalpha(t_color *c, t_color bg);
void			ft_resrect(t_rect *rect, t_rect bounds);

t_color			ft_imagept(t_image *img, t_pt pt);
t_color			ft_imagepos(t_image *img, int pos);
void			ft_imageput(t_image *img, int pos, t_color color);
void			ft_imageclr(t_image *img);
void			ft_imageclrc(t_image *img, t_color color);
t_image			*ft_imageclone(t_image *img);
void			ft_imageclonekil(t_image *clone);

void			ft_drawxy(t_image *img, int x, int y, t_color color);
void			ft_drawpt(t_image *img, t_pt pt, t_color color);
void			ft_drawnpt(t_image *img, t_pt pt, int n, t_color color);

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
** Read a file line per line.
** 'line' is not a buffer.
** =============
** Return 1 if a line is read, 0 if the end of file is reach
** or -1 if an error occured.
*/
int				get_next_line(int const fd, char **line);

/*
** Clear the cache relative to the fd.
** Call it after close a fd if the end of file is not reach
*/
void			gnl_clear_cache(int const fd);

#endif
