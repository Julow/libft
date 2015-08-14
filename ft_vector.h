/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 02:55:42 by juloo             #+#    #+#             */
/*   Updated: 2015/08/14 22:22:54 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H
	
/*
** ========================================================================== **
** Storage
** -
** Cool for:
**   Stack (fast push/pop)
**   Queue (or double queue) (fast push/pop back/front)
**   Priority queue (fast insert/pop)
**   Instable vector (fast push/remove)
**   Temporary vector (fast push back/iter/clear)
** -
** Extendable for:
**   Sorted set (fast insert/chunk jump)
** ---
** + fast push/pop
** + fast insert/remove
** + fast push_front/pop_front
** + fast alloc front/back/insert
** + iterator (+ fast)
** + insert/remove while itering
** + memory efficient
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
	const int		element_size;
	t_vec_c			*first;
	t_vec_c			*last;
}				t_vector;

typedef struct	s_vector_it
{
	t_vector		*vector;
	t_vec_c			*next;
	void			*data;
	void			*end;
}				t_vector_it;

/*
** Create a vector
** Take the type of an element as param
*/
# define VECTOR(t)			((t_vector){0, sizeof(t), NULL, NULL})

/*
** Create a vector iterator
** The iterator is invalid until the first call to VECTOR_NEXT
*/
# define VECTOR_IT(v)		((t_vector_it){(v), (v)->first, NULL, NULL})

/*
** Increment the iterator
** At the end the iterator become invalid and NULL is returned
*/
# define VECTOR_NEXT(i)		(VECTOR_IT_NEXT(i) ? vector_it_c(&i) : i.data)

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
** Pointer returned by previous call to VECTOR_NEXT become invalid
** Next call to VECTOR_NEXT jump over the new element
*/
void			*ft_vinsert(t_vector_it *it, void *data);

/*
** Remove at iterator position
** Pointer returned by last call to VECTOR_NEXT become invalid
*/
void			ft_vremove(t_vector_it *it);

/*
** Completly free all datas
** The vector is reusable after a clear
*/
void			ft_vclear(t_vector *v);

/*
** Internaly used
*/
# define VECTOR_IT_NEXT(i)	((i.data += i.vector->element_size) >= i.end)

void			*vector_it_c(t_vector_it *it);

void			vector_c_del(t_vector *v, t_vec_c *c);

void			vector_c_after(t_vector *v, t_vec_c *c);
void			vector_c_before(t_vector *v, t_vec_c *c);

#endif
