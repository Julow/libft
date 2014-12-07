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

# include <stddef.h>

# define MAL(t,l)	((t*)ft_malloc(sizeof(t) * (l)))
# define MAL1(t)	((t*)ft_malloc(sizeof(t)))

# define UCHAR		unsigned char
# define UINT		unsigned int
# define LONG		long long int
# define ULONG		unsigned long long int

typedef char	t_bool;
typedef UCHAR	t_uchar;
typedef UINT	t_uint;
typedef LONG	t_long;
typedef ULONG	t_ulong;

# ifndef TRUE
#  define TRUE		1
# endif
# ifndef FALSE
#  define FALSE		0
# endif
# ifndef ERROR
#  define ERROR		-1
# endif

typedef struct	s_lst
{
	void			*data;
	struct s_lst	*next;
}				t_lst;

typedef struct	s_array
{
	void			**data;
	int				length;
	int				alloc_length;
}				t_array;

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

/*
** Memory
*/
void			*ft_malloc(t_uint size);

void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
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
char			*ft_strchr(const char *s, int c);
int				ft_strchri(char *str, char c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);

void			ft_strnadd(char **str, char const *add, size_t len);

t_bool			ft_isalpha(char c);
t_bool			ft_isdigit(char c);
t_bool			ft_isalnum(char c);
t_bool			ft_isascii(char c);
t_bool			ft_isprint(char c);
t_bool			ft_isspace(char c);
t_bool			ft_iswhite(char c);

t_bool			ft_isato(const char *str);
t_bool			ft_isnumber(const char *str);

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

char			ft_toupper(char c);
char			ft_tolower(char c);
void			ft_strlower(char *str);
void			ft_strupper(char *str);

/*
** Write
*/
void			ft_putchar(char c);
void			ft_putnchar(char c, int n);
void			ft_putstr(char const *s);
void			ft_putlstr(char const *s, int len);
void			ft_putendl(char *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putnchar_fd(char c, int n, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putlstr_fd(char const *s, int len, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
** Store pointers using the struct s_lst (t_lst)
*/
t_lst			*ft_lstnew(void *data);
void			ft_lstadd(t_lst **alst, t_lst *add);
void			ft_lstafter(t_lst *lst, t_lst *add);
void			ft_lstdel(t_lst **alst, void (*f)(void*));
void			ft_lstdelnext(t_lst *lst, void (*f)(void*));
void			ft_lstdelone(t_lst **alst, void (*f)(void*));
void			ft_lstiter(t_lst *lst, void (*f)(void *data));
t_lst			*ft_lstmap(t_lst *lst, t_lst *(*f)(t_lst*));

/*
** Store pointers using the struct s_array (t_array)
** Allocate memory by block of 16 to reduce the number of free/malloc/copy
*/
t_array			*ft_arraynew(void);
void			ft_arrayadd(t_array *array, void *add);
void			ft_arrayset(t_array *array, void *set, int index);
void			ft_arrayins(t_array *array, void *ins, int index);
void			*ft_arrayrem(t_array *array, int index);
int				ft_arraychr(t_array *array, void *chr);
void			ft_arrayapp(t_array *array, t_array *app);
void			ft_arrayfree(t_array *array);
void			ft_arrayclr(void *array, void (*f)(void *data));
void			ft_arraykil(void *array, void (*f)(void *data));
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
void			ft_stringaddc(t_string *str, char c);
void			ft_stringadd(t_string *str, char *add);
void			ft_stringaddi(t_string *str, int nbr);
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

#endif
