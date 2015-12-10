/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/07 23:07:10 by juloo             #+#    #+#             */
/*   Updated: 2015/12/10 19:19:15 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WCHAR_H
# define FT_WCHAR_H

# include "ft/libft.h"
# include <wchar.h>

uint32_t		ft_wstrlen(wchar_t const *wstr);
int				ft_wstrconv(char *buff, wchar_t const *wstr);
int				ft_wstrnconv(char *buff, wchar_t const *wstr, int n);
int				ft_widetoa(char *buff, int w);

#endif
