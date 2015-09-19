/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 02:55:42 by juloo             #+#    #+#             */
/*   Updated: 2015/09/19 11:26:49 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQUE_H
# define FT_DEQUE_H

# include "libft.h"
	
/*
** ========================================================================== **
** Array list
** -
** Storage
*/

typedef struct	s_que_c
{
	int				start;
	int				end;
	struct s_que_c	*next;
	struct s_que_c	*prev;
}				t_que_c;

# define QUE_C_DATA(c)		(((void*)(c)) + sizeof(t_que_c))

# define QUE_C_SIZE			256

struct			s_deque
{
	int				length;
	const int		element_size;
	t_que_c			*first;
	t_que_c			*last;
};

struct			s_deque_it
{
	t_deque			*deque;
	t_que_c			*next;
	void			*data;
	void			*end;
};

/*
** Create a deque
** Take the type of an element as param
*/
# define DEQUE(t)			((t_deque){0, sizeof(t), NULL, NULL})

/*
** Create a deque iterator
** The iterator is invalid until the first call to deque_NEXT
*/
# define DEQUE_IT(v)		((t_deque_it){(v), (v)->first, NULL, NULL})

/*
** Increment the iterator
** At the end the iterator become invalid and NULL is returned
*/
# define DEQUE_NEXT(i)		(deque_IT_NEXT(i) ? deque_it_c(&i) : i.data)

/*
** Add an element to the back of the deque
** if 'data' is not NULL then copy it else bzero
** Return a pointer to the new element
*/
void			*ft_qpush_back(t_deque *v, void *data);

/*
** Remove the last element of the deque
** if 'data' is not NULL then fill it with the old value
*/
void			ft_qpop_back(t_deque *v, void *data);

/*
** Add an element to the front of the deque
** if 'data' is not NULL then copy it else bzero
** Return a pointer to the new element
*/
void			*ft_qpush_front(t_deque *v, void *data);

/*
** Remove the first element of the deque
** if 'data' is not NULL then fill it with the old value
*/
void			ft_qpop_front(t_deque *v, void *data);

/*
** Remove at iterator position
** Pointer returned by last call to deque_NEXT become invalid
*/
void			ft_qremove(t_deque_it *it);

/*
** Completly free all datas
** The deque is reusable after a clear
*/
void			ft_qclear(t_deque *v);

/*
** Internaly used
*/
# define deque_IT_NEXT(i)	((i.data += i.deque->element_size) >= i.end)

void			*deque_it_c(t_deque_it *it);

void			deque_c_del(t_deque *v, t_que_c *c);

void			deque_c_after(t_deque *v, t_que_c *c);
void			deque_c_before(t_deque *v, t_que_c *c);

#endif
