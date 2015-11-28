/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 17:00:20 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/27 23:45:41 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OUT_H
# define FT_OUT_H

# include "ft/libft.h"

typedef struct s_out		t_out;

/*
** ========================================================================== **
** Out stream
** --
** Handle conversions and formating
** Flags:
**  OUT_CENTER		Center aligned
**  OUT_TOUPPER		To upper case
**  OUT_TOLOWER		To lower case
**  OUT_REVCASE		Reverse case
**  OUT_PLUS		Add '+' symbol for positive numbers
**  OUT_SPACE		Add ' ' for positive numbers (overrided by OUT_PLUS)
**  OUT_MINUS		Width as negative
**  OUT_GROUP		(not implemented)
*/

# define OUT_CENTER		(1 << 1)
# define OUT_GROUP		(1 << 2)
# define OUT_PLUS		(1 << 3)
# define OUT_SPACE		(1 << 4)
# define OUT_TOUPPER	(1 << 5)
# define OUT_TOLOWER	(1 << 6)
# define OUT_MINUS		(1 << 7)
# define OUT_REVCASE	(OUT_TOLOWER | OUT_TOUPPER)

struct			s_out
{
	char			*buff;
	void			(*flush)();
	uint32_t		buff_i;
	uint32_t		buff_size;
	t_sub			base;
	char			fill;
	uint8_t			precision;
	uint16_t		flags;
	int16_t			width;
};

# define OUT(BUFF,SIZE,F)	((t_out){(BUFF), (F), 0, (SIZE), _OUT_DEFAULT})

# define OUT_DEFAULT_FILL		' '
# define OUT_DEFAULT_BASE		SUBC(BASE_10)
# define OUT_DEFAULT_WIDTH		0

/*
** Write a string
** if 'len' is negative use the same rule as ft_sub
*/
void			ft_putstr(t_out *out, char const *data, int32_t len);

/*
** Write a sub
*/
void			ft_putsub(t_out *out, t_sub sub);

/*
** Write a char
*/
void			ft_putchar(t_out *out, char c);

/*
** Write 'n' time the char 'c'
*/
void			ft_putnchar(t_out *out, char c, uint32_t n);

/*
** Write the representation of an int
*/
void			ft_putint(t_out *out, int64_t val);
void			ft_putuint(t_out *out, uint64_t val);

/*
** Write the representation of a float
*/
void			ft_putfloat(t_out *out, double val);

/*
** Put a '\n' without formating and flush
*/
void			ft_putendl(t_out *out);

/*
** Write without formating
*/
void			ft_write(t_out *out, char const *str, uint32_t len);
void			ft_write_char(t_out *out, char c);
void			ft_write_nchar(t_out *out, char c, uint32_t n);

/*
** Put padding (width)
** ft_putpad_right also reset 'fill', 'width' and 'flags' fields
*/
void			ft_putpad_left(t_out *out, int32_t len);
void			ft_putpad_right(t_out *out, int32_t len);

/*
** Flush
*/
void			ft_flush(t_out *out);

# define _OUT_DEFAULT	OUT_DEFAULT_BASE,OUT_DEFAULT_FILL,0,0,OUT_DEFAULT_WIDTH

#endif
