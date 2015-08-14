/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 01:50:16 by juloo             #+#    #+#             */
/*   Updated: 2015/08/14 01:55:45 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_H
# define FT_ARRAY_H

# include "libft.h"

/*
** ========================================================================== **
** Storage
** -
** Deprecated
*/

# define AG(t,a,i)		((t)(((t_array*)(a))->data[i]))

typedef struct	s_array
{
	void			**data;
	int				length;
	int				alloc_length;
}				t_array;

t_array			*ft_arraynew(void);
void			ft_arrayini(t_array *array);
void			ft_arrayadd(t_array *array, void *add);
void			ft_arrayset(t_array *array, void *set, int index);
void			ft_arrayins(t_array *array, void *ins, int index);
void			*ft_arrayrem(t_array *array, int index);
void			*ft_arraypop(t_array *array);
int				ft_arraychr(t_array *array, const void *chr);
void			ft_arrayapp(t_array *array, const t_array *app);
t_array			*ft_arraydup(const t_array *array);
void			ft_arrayfree(t_array *array);
void			ft_arrayclr(void *array, void (*f)(void *data));
void			ft_arraykil(void *array, void (*f)(void *data));
void			ft_arraykilf(void *array);
void			ft_arrayswap(t_array *array, int i1, int i2);
void			ft_arrayrev(t_array *array);
t_bool			ft_arrayext(t_array *array, int need);

#endif
