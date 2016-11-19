/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_in.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 22:18:02 by juloo             #+#    #+#             */
/*   Updated: 2016/11/19 19:39:43 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFF_IN_H
# define BUFF_IN_H

# include "ft/ft_in.h"
# include "ft/libft.h"

typedef struct s_buff_in			t_buff_in;

/*
** ========================================================================== **
** Buffered in
** -
** TODO: export to it's own module
*/

/*
** in				=> source stream
** buff				=> buffer
** buff_end			=> end offset in the buffer
** buff_capacity	=> allocated buff size
*/
struct			s_buff_in
{
	t_in			*in;
	char			*buff;
	uint32_t		i;
	uint32_t		length;
	uint32_t		buff_capacity;
};

# define BUFF_IN(IN)		((t_buff_in){(IN), NULL, 0, 0, 0})

# define BUFF_IN_MIN_BUFF	32

/*
** Check if 'B.i + I' is a valid index
** Read if needed
*/
# define BUFF_IN_CHECK(B,I)	(((B).i+(I)) < (B).length || ft_buff_in_read(&(B)))

/*
** Return char at 'B.i + I'
*/
# define BUFF_IN_GETC(B,I)	((B).buff[(B).i + (I)])

/*
** Read a full buffer from the source stream
** Discard characters not in the range ['i', 'length')
** Return true on success, false on EOF
*/
bool			ft_buff_in_read(t_buff_in *in);

/*
** Inject 'str' in the buffer at the current position
*/
void			ft_buff_in_inject(t_buff_in *in, t_sub str);

/*
** Clear/free
** The object is reusable after a clear
*/
void			ft_buff_in_clear(t_buff_in *in);

#endif
