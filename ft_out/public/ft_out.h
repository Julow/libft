/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 17:00:20 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/13 22:11:07 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OUT_H
# define FT_OUT_H

# include "libft.h"

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
**  OUT_GROUP		(not implemented)
*/

# define OUT_CENTER		(1 << 1)
# define OUT_GROUP		(1 << 2)
# define OUT_PLUS		(1 << 3)
# define OUT_SPACE		(1 << 4)
# define OUT_TOUPPER	(1 << 5)
# define OUT_TOLOWER	(1 << 6)
# define OUT_REVCASE	(OUT_TOLOWER | OUT_TOUPPER)

struct			s_out
{
	char			*buff;
	void			(*flush)(t_out *);
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

void			ft_write(t_out *out, char const *data, int32_t len);
void			ft_write_sub(t_out *out, t_sub sub);
void			ft_write_char(t_out *out, char c);
void			ft_write_nchar(t_out *out, char c, uint32_t n);

void			ft_write_int(t_out *out, int64_t val);
void			ft_write_uint(t_out *out, uint64_t val);
void			ft_write_float(t_out *out, double val);

void			ft_write_endl(t_out *out);

void			ft_flush(t_out *out);

# define _OUT_DEFAULT	OUT_DEFAULT_BASE,OUT_DEFAULT_FILL,0,0,OUT_DEFAULT_WIDTH

#endif
