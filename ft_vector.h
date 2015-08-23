/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 12:22:40 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/23 15:10:25 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include "libft.h"

/*
** ========================================================================== **
** Vector (Continuous dynamic array)
*/

typedef struct	s_vector
{
	void			*data;
	int				length;
	int				capacity;
	int const		element_size;
}				t_vector;

# define VECTOR_MIN_CAP		16

# define VECTOR(t)			((t_vector){NULL, 0, 0, sizeof(t)})

/*
** Get an element by index
** t		type
** v		vector
** i		index
*/
# define VECTOR_GET(t,v,i)	(((t*)(v)->data) + i)

/*
** Push 'count' elements to the back of the vector
** if 'data' is not NULL it is copied else bzero
** Return a pointer to the first new element
*/
void			*ft_vpush_back(t_vector *v, void *data, int count);

/*
** Remove a span of elements
** if index < 0 it's set to v->length + index
** if count < 0 it's set to v->length - index + count
*/
void			ft_vremove(t_vector *v, int index, int count);

/*
** Extend the vector to store 'count' elements
** Do nothing if there already enougth space
*/
void			ft_vreserve(t_vector *v, int count);

#endif
