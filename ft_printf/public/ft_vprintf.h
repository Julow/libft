/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 01:06:07 by juloo             #+#    #+#             */
/*   Updated: 2015/11/15 20:25:33 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VPRINTF_H
# define FT_VPRINTF_H

# include "ft_out.h"
# include <stdarg.h>

void	ft_vprintf(char const *format, va_list ap);
void	ft_vdprintf(int fd, char const *format, va_list ap);
void	ft_vfprintf(t_out *out, char const *format, va_list ap);
void	ft_vsprintf(char *buff, char const *format, va_list ap);
void	ft_vsnprintf(char *buff, uint32_t len, char const *format, va_list ap);

void	ft_put_f(t_out *out, char const *format, va_list *ap);

#endif
