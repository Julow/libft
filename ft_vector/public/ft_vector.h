/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 12:22:40 by jaguillo          #+#    #+#             */
/*   Updated: 2016/02/01 22:26:56 by juloo            ###   ########.fr       */
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

struct			s_vector
{
	void			*data;
	uint32_t		length;
	uint32_t		capacity;
	uint32_t const	element_size;
};

# define VECTOR_MIN_CAP		16

# define VECTOR(T)			((t_vector){NULL, 0, 0, sizeof(T)})
# define VECTORC(A)			((t_vector){V(A), ARRAY_LEN(A), 0, sizeof((A)[0])})

/*
** Get an element by index
** V		vector
** I		index (used once)
** (params are used once)
*/
# define VECTOR_GET(V,I)	((V).data + ((V).element_size * (I)))

/*
** Add 'count' element to the end
** If 'data' is not NULL, copy 'data'
** Return a pointer to the new elements
*/
void		*ft_vpush(t_vector *v, void *data, uint32_t count);

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
