/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 12:22:40 by jaguillo          #+#    #+#             */
/*   Updated: 2016/08/14 14:37:36 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include "ft/libft.h"

typedef struct s_vector		t_vector;

/*
** ========================================================================== **
** Vector (Dynamic array)
*/

struct		s_vector
{
	void			*data;
	uint32_t		length;
	uint32_t		capacity;
	uint32_t const	element_size;
};

# define VECTOR_MIN_CAP		16

/*
** VECTOR(TYPE, ...)		Create a vector of TYPE (... are default elements)
** VECTORC(ARRAY)			Create a vector from a literal array
** -
** VECTOR_IT(V)				Start iterator
** VECTOR_NEXT(V+, IT+)		Increment iterator
** -
** VECTOR_END(V+)			Pointer to the end of the vector
** -
** VECTOR_GET(V+, INDEX)	Get an element by index
** VECTOR_LAST(V+)			Get the last element
** VECTOR_OFF(V, INDEX)		Get the byte offset for an index
** -
** VGET(TYPE, V+, INDEX)	Get an element by index (cast to TYPE)
** VGETC(TYPE, V+, INDEX)	Get an element by index (cast to TYPE const)
** -
** VLAST(TYPE, V+)			Get the last element (cast to TYPE)
*/

# define VECTOR_IT(V)		((V).data - (V).element_size)
# define VECTOR_NEXT(VC,IT)	(V(IT = V(IT) + (VC).element_size) < VECTOR_END(VC))

# define VECTOR_END(V)		((V).data + ((V).length * (V).element_size))

# define VECTOR_GET(V,I)	((V).data + VECTOR_OFF(V, I))
# define VECTOR_LAST(V)		((V).data + VECTOR_OFF(V, (V).length - 1))
# define VECTOR_OFF(V,I)	((V).element_size * (I))

# define VGET(TYPE,V,I)		(*((TYPE*)VECTOR_GET(V, I)))
# define VGETC(TYPE,V,I)	(VGET(TYPE const, V, I))

# define VLAST(T, V)		(VGET(T, V, (V).length - 1))

# define VECTOR(TYPE, ...)	(_VECTOR(((TYPE[]){__VA_ARGS__}), TYPE))
# define VECTORC(ARRAY)		(_VECTOR((ARRAY), ((ARRAY)[0])))

# define _VECTOR(A,S)		((t_vector){V(A), ARRAY_LEN(A), 0, sizeof(S)})

/*
** Add 'count' element to the end
** If 'data' is not NULL, copy 'data'
** Return a pointer to the new elements
*/
void		*ft_vpush(t_vector *v, void const *data, uint32_t count);

/*
** Change span length
** (Insert/remove spans of element)
** Change the length of the span 'span' to 'n' elements
** If 'data' is not NULL, copy 'n' elements, else do not initialize data
** Return a ptr to the start of the new span
*/
void		*ft_vspan(t_vector *v, t_vec2u span, void const *data, uint32_t n);

/*
** Change capacity
** Use length if length > 'capacity'
*/
void		ft_vreserve(t_vector *v, uint32_t capacity);

/*
** Completly free all datas
** The vector is reusable after a clear
*/
void		ft_vclear(t_vector *v);

#endif
