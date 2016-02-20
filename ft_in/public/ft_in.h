/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 19:45:32 by juloo             #+#    #+#             */
/*   Updated: 2016/02/20 14:38:02 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IN_H
# define FT_IN_H

# include "ft/ft_dstr.h"
# include "ft/libft.h"

typedef struct s_in			t_in;

/*
** ========================================================================== **
** In stream
** -
** TODO: ft_readto_str
*/

struct		s_in
{
	char const	*buff;
	bool		(*refresh)(t_in*);
	uint32_t	buff_i;
	uint32_t	buff_len;
};

# define IN(B,S,R)			((t_in){(B), (void*)(R), 0, (S)})

/*
** Return the next char on the buffer without moving the cursor
** Refresh the buffer if needed
** Return EOF on end-of-file
*/
# define IN_PEEK(IN)		(IN_REFRESH(IN) ? (IN)->buff[(IN)->buff_i] : EOF)

/*
** Like IN_PEEK but increment the cursor
*/
# define IN_READ(IN)		(IN_REFRESH(IN) ? (IN)->buff[(IN)->buff_i++] : EOF)

# define IN_READ_IF(IN,C)	((IN_PEEK(IN) == (C)) ? ++((IN)->buff_i) : false)

/*
** Refresh the buffer if needed
** Return false on end-of-file, true otherwise
*/
# define IN_REFRESH(IN)		((IN)->buff_i < (IN)->buff_len || ft_in_refresh(IN))

/*
** Read and copy 'n' char to 'dst'
** 'dst' can be NULL, it will ignore chars
** Return false on end-of-file, true otherwise
*/
bool		ft_read(t_in *in, char *dst, uint32_t n);

/*
** Read and copy char to 'dst' until 'end' parameter match
** 'dst' can be NULL
** 'dst' is not cleared
** Return false on end-of-file but it may have copied char into 'dst'
** Return true otherwise
*/
bool		ft_readto_str(t_in *in, t_sub end, t_dstr *dst);
bool		ft_readto_char(t_in *in, char end, t_dstr *dst);
bool		ft_readto_if(t_in *in, t_is end, t_dstr *dst);
bool		ft_readto_not(t_in *in, t_is end, t_dstr *dst);
bool		ft_readto_func(t_in *in, bool (*f)(char, void*), void *env,
				t_dstr *dst);

/*
** Like IN_REFRESH
*/
bool		ft_in_refresh(t_in *in);

#endif
