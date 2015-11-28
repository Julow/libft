/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 19:25:33 by juloo             #+#    #+#             */
/*   Updated: 2015/11/27 23:45:27 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SUB_H
# define FT_SUB_H

# include "ft/libft.h"

/*
** ========================================================================== **
** ft::sub
** ---
** Operation on sub
*/

t_sub			ft_subsub(t_sub sub, int from, int to);

t_bool			ft_subequ(t_sub a, t_sub b);

int				ft_subtrim(t_sub *sub, t_is mask);
int				ft_subtrimr(t_sub *sub, t_is mask);
int				ft_subtriml(t_sub *sub, t_is mask);

t_bool			ft_subnext(t_sub *sub, t_is mask);
t_bool			ft_subnextc(t_sub *sub, char c);
int				ft_subcount(t_sub sub, t_is mask);
int				ft_subextract(t_sub sub, t_sub *dst, int max, t_is mask);

int				ft_subindex(t_sub sub, char c);
int				ft_subchr(t_sub sub, t_is mask);

int				ft_subint(t_sub sub, int *dst);

/*
** ft_subfloat
** -
** Parse a float number
** Stop at the first invalid char
** Store result in the *f param
** -
** Return the length of the float (in the string)
**  on error return 0 (0 char parsed)
** -
** Allow hexa (0x) and binary (0b) number
** -
** Valid float:
**  -?[0-9]*([.,][0-9]*)?
*/
int				ft_subfloat(t_sub sub, float *f);

#endif
