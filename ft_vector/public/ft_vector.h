/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 12:22:40 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/11 19:49:53 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include "libft.h"

typedef struct s_vector		t_vector;

/*
** ========================================================================== **
** Vector (Continuous dynamic array)
*/

struct			s_vector
{
	void			*data;
	int				length;
	int				capacity;
	int const		element_size;
};

# define VECTOR_MIN_CAP		16

# define VECTOR(t)			((t_vector){NULL, 0, 0, sizeof(t)})

/*
** Get an element by index
** v		vector
** i		index (used once)
*/
# define VECTOR_GET(v,i)	(((v).data) + ((i) * (v).element_size))

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

/*
** Completly free all datas
** The vector is reusable after a clear
*/
void			ft_vclear(t_vector *v);

#endif
