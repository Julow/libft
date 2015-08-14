/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 02:55:42 by juloo             #+#    #+#             */
/*   Updated: 2015/08/14 17:08:32 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H
	
/*
** ========================================================================== **
** Storage
** -
** Cool for:
**   Stack (push/pop)
**   Queue (or double queue) (push/pop back/front)
**   Priority queue (insert/pop)
**   Instable vector (push/remove)
** ---
** + fast push/pop
** + fast insert/remove
** + fast push_front/pop_front
** + fast alloc front/back/insert
** + iterator (+ fast)
** + insert/remove while itering
** - slow random access
*/

typedef struct	s_vec_c
{
	int				start;
	int				end;
	struct s_vec_c	*next;
	struct s_vec_c	*prev;
}				t_vec_c;

# define VEC_C_DATA(c)		(((void*)(c)) + sizeof(t_vec_c))

# define VEC_C_SIZE			256

typedef struct	s_vector
{
	int				length;
	int				element_size;
	t_vec_c			*first;
	t_vec_c			*last;
}				t_vector;

typedef struct	s_vector_it
{
	t_vector		*vector;
	t_vec_c			*next;
	void			*curr;
	void			*end;
}				t_vector_it;

/*
** Create a vector
** Take the size of a single element as param
*/
# define VECTOR(s)			((t_vector){0, (s), NULL, NULL})

/*
** Create a vector iterator
** Take a pointer of vector as param
*/
# define VECTOR_IT(v)		((t_vector_it){(v), (v)->first, NULL, NULL})

/*
** Increment the iterator
** Take an iterator as param
*/
# define VECTOR_NEXT(i)		(VECTOR_IT_NEXT(i) ? vector_it_c(&i) : i.curr)

/*
** iterator usage:
** -
** check_all_mdr(t_vector *v)
** {
** 	t_vector_it		it;
** 	t_mdr			*mdr;
** -
** 	it = VECTOR_IT(vector);
** 	while (mdr = VECTOR_NEXT(it))
** 	{
** 		if (!check_mdr(mdr))
** 			ft_vremove(&it);
** 	}
** }
*/

/*
** Add an element to the back of the vector
** if 'data' is not NULL then copy it else bzero
** Return a pointer to the new element
*/
void			*ft_vpush_back(t_vector *v, void *data);

/*
** Remove the last element of the vector
** if 'data' is not NULL then fill it with the old value
*/
void			ft_vpop_back(t_vector *v, void *data);

/*
** Add an element to the front of the vector
** if 'data' is not NULL then copy it else bzero
** Return a pointer to the new element
*/
void			*ft_vpush_front(t_vector *v, void *data);

/*
** Remove the first element of the vector
** if 'data' is not NULL then fill it with the old value
*/
void			ft_vpop_front(t_vector *v, void *data);

/*
** Insert at iterator position
** if 'data' is not NULL then copy it else bzero
** Return a pointer to the new element
** Iterator is invalid until next call to VECTOR_NEXT
** Next call to VECTOR_NEXT jump over the new element
*/
void			*ft_vinsert(t_vector_it *it, void *data);

/*
** Remove at iterator position
** Iterator is invalid until next call to VECTOR_NEXT
*/
void			ft_vremove(t_vector_it *it, void *data);

/*
** Internaly used
*/
# define VECTOR_IT_NEXT(i)	((i.curr += i.vector->element_size) >= i.end)

void			*vector_it_c(t_vector_it *it);

void			vector_c_after(t_vector *v, t_vec_c *c);
void			vector_c_before(t_vector *v, t_vec_c *c);

#endif
