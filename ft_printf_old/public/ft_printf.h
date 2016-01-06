/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 15:36:06 by juloo             #+#    #+#             */
/*   Updated: 2015/11/07 15:36:20 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

/*
** ========================================================================== **
** A format sequence be like:
**    %[flags][width][.precision]format
** flags can be 0 or more: '#', ' ', '-', '+', '^', '0', ''', '>', 'm', 'M'
** width is a positive integer
** precision is a positive integer or '*', precision start with '.'
** format can be one of "%sSdDoOuUxXicCnpfFeE"
** A meta sequence be like:
**    {meta_name}
** (list of meta in srcs/ft_printf/parse_meta.c)
** -
** ft_printf
** -
** Process the format sequence like printf and print the result to stdout
** -
** Return the total of char printed.
*/

int				ft_printf(const char *format, ...);
int				ft_fdprintf(const int fd, const char *format, ...);
int				ft_sprintf(char *dst, char const *format, ...);
int				ft_snprintf(char *dst, int max_len, char const *format, ...);

#endif
