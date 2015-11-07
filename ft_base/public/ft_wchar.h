/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/07 23:07:10 by juloo             #+#    #+#             */
/*   Updated: 2015/06/07 23:09:09 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WCHAR_H
# define FT_WCHAR_H

# include "libft.h"
# include <wchar.h>

t_uint			ft_wstrlen(wchar_t *wstr);
int				ft_wstrconv(char *buff, wchar_t *wstr);
int				ft_wstrnconv(char *buff, wchar_t *wstr, int n);
int				ft_widetoa(char *buff, int w);

#endif
