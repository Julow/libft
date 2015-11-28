/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 01:06:07 by juloo             #+#    #+#             */
/*   Updated: 2015/11/27 23:45:36 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VPRINTF_H
# define FT_VPRINTF_H

# include "ft/ft_out.h"
# include <stdarg.h>

void	ft_vprintf(char const *format, va_list ap);
void	ft_vdprintf(int fd, char const *format, va_list ap);
void	ft_vfprintf(t_out *out, char const *format, va_list ap);
void	ft_vsprintf(char *buff, char const *format, va_list ap);
void	ft_vsnprintf(char *buff, uint32_t len, char const *format, va_list ap);

void	ft_putf(t_out *out, char const *format, va_list *ap);

#endif
