/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 19:45:32 by juloo             #+#    #+#             */
/*   Updated: 2015/12/06 01:44:33 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IN_H
# define FT_IN_H

# include "ft/libft.h"
# include "ft/ft_dstr.h"

typedef struct s_in			t_in;

/*
** ========================================================================== **
** In stream
** -
** TODO: ft_readto_str
*/

struct s_in
{
	char const	*buff;
	t_bool		(*refresh)(t_in*);
	uint32_t	buff_i;
	uint32_t	buff_len;
};

# define IN(B,S,R)		((t_in){(B), (void*)(R), 0, (S)})

/*
** Return the next char on the buffer without moving the cursor
** Refresh the buffer if needed
** Return EOF on end-of-file
*/
# define IN_PEEK(IN)	(IN_REFRESH(IN) ? (IN)->buff[(IN)->buff_i] : EOF)

/*
** Like IN_PEEK but increment the cursor
*/
# define IN_READ(IN)	(IN_REFRESH(IN) ? (IN)->buff[(IN)->buff_i++] : EOF)

/*
** Refresh the buffer if needed
** Return false on end-of-file, true otherwise
*/
# define IN_REFRESH(IN)	((IN)->buff_i < (IN)->buff_len || ft_in_refresh(IN))

/*
** Read and copy 'n' char to 'dst'
** 'dst' can be NULL, it will ignore chars
** Return false on end-of-file, true otherwise
*/
t_bool			ft_read(t_in *in, char *dst, uint32_t n);

/*
** Read and copy char to 'dst' until 'end' parameter match
** 'dst' can be NULL
** 'dst' is not cleared
** 'end' is not copied into 'dst' but is read
** Return false on end-of-file but it may have copied char into 'dst'
** Return true otherwise
*/
t_bool			ft_readto_char(t_in *in, char end, t_dstr *dst);
t_bool			ft_readto_if(t_in *in, t_is end, t_dstr *dst);

/*
** Like IN_REFRESH
*/
t_bool			ft_in_refresh(t_in *in);

#endif
