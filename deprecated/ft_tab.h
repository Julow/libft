/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 15:53:20 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/23 15:54:01 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAB_H
# define FT_TAB_H

# include "libft.h"

/*
** ========================================================================== **
** Store mem using the struct s_tab (t_tab)
*/

# define TI(b,i)		(((t_tab*)(b))->data + (((t_tab*)(b))->size * (i)))
# define TG(t,b,i)		((t*)TI(&(b), (i)))

typedef struct	s_tab
{
	t_byte			*data;
	int				length;
	int				bytes;
	int				alloc_bytes;
	int				size;
}				t_tab;

t_tab			*ft_tabnew(int size);
void			ft_tabini(t_tab *tab, int size);
void			*ft_tabget(t_tab *tab, int index);
void			*ft_tabadd0(t_tab *tab);
void			ft_tabadd(t_tab *tab, const void *add);
void			ft_tabaddn(t_tab *tab, const void *add, int n);
void			ft_tabset(t_tab *tab, const void *set, int index, int n);
void			ft_tabins(t_tab *tab, const void *ins, int index, int n);
void			ft_tabrem(t_tab *tab, int index, int n);
void			ft_tabrot(t_tab *tab, int rot);
void			ft_tabpop(t_tab *tab);
int				ft_tabchr(t_tab *tab, const void *chr);
t_bool			ft_tabiter(t_tab *tab, t_bool (*f)(), void *data);
void			ft_tabfree(t_tab *tab);
void			ft_tabclr(t_tab *tab);
void			ft_tabkil(void *tab);
void			ft_tabswap(t_tab *tab, int i1, int i2);
void			ft_tabrev(t_tab *tab);
t_bool			ft_tabext(t_tab *tab, int need);

#endif
