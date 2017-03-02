/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sumset.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 21:42:22 by juloo             #+#    #+#             */
/*   Updated: 2017/03/02 17:31:42 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUMSET_H
# define SUMSET_H

# include "ft/libft.h"
# include "ft/set.h"

typedef struct s_sumset			t_sumset;
typedef struct s_sumset_node	t_sumset_node;

/*
** ========================================================================== **
** Prefix sum table
*/

/*
** Sumset object
** -
** SUMSET()			Constructor
** SUMSET_LENGTH(S)	Return the number of element
** SUMSET_SUM(S)	Return the sum at the end of the set
*/
struct			s_sumset
{
	t_set			set;
};

# define SUMSET()			((t_sumset){SET(NULL, &sumset_node_update)})
# define SUMSET_LENGTH(S)	((S).set.count)
# define SUMSET_SUM(S)		((S).set.root ? _SUMSET_SUM(S) : 0)

/*
** Return the sum of all the element before and the value at 'index'
** -
** 'index' must be <= to SUMSET_LENGTH(s)
*/
t_vec2u			ft_sumset_get(t_sumset const *s, uint32_t index);

/*
** Return the last index with sum <= 'sum'
**  and the sum at that index - 'sum'
** -
** 'sum' must be <= to SUMSET_SUM(s)
*/
t_vec2u			ft_sumset_index(t_sumset const *s, uint32_t sum);

/*
** Insert 'value' at 'index'
** -
** 'index' must be <= to SUMSET_LENGTH(s)
*/
void			ft_sumset_insert(t_sumset *s, uint32_t index, uint32_t value);

/*
** Set the value at 'index' to 'value'
** -
** 'index' must be < to SUMSET_LENGTH(s)
*/
void			ft_sumset_set(t_sumset *s, uint32_t index, uint32_t value);

/*
** Add 'add' to the value at 'index'
** The resulting value should not be < 0
** -
** 'index' must be < to SUMSET_LENGTH(s)
*/
void			ft_sumset_add(t_sumset *s, uint32_t index, int32_t add);

/*
** Remove the value at 'index'
** -
** Return the deleted value
*/
uint32_t		ft_sumset_remove(t_sumset *s, uint32_t index);

/*
** -
*/

# define _SUMSET_SUM(S)		((t_sumset_node const*)(S).set.root)->value_sum

struct			s_sumset_node
{
	t_set_h			set_h;
	uint32_t		value;
	uint32_t		length_sum;
	uint32_t		value_sum;
};

void			sumset_node_update(t_sumset_node *node);

#endif
