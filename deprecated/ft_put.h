/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 16:39:32 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/17 16:40:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUT_H
# define FT_PUT_H

# include "libft.h"

/*
** ========================================================================== **
** Write
*/

int				ft_puts(const char *s);
int				ft_putchar(char c);
int				ft_putnchar(char c, int n);
int				ft_putstr(const char *str);
int				ft_putlstr(const char *str, int len);
int				ft_putendl(const char *s);
int				ft_putnbr(int n);
int				ft_putlong(t_long n);
int				ft_putchar_fd(char c, int fd);
int				ft_putnchar_fd(char c, int n, int fd);
int				ft_putstr_fd(const char *s, int fd);
int				ft_putlstr_fd(const char *s, int len, int fd);
int				ft_putendl_fd(const char *s, int fd);
int				ft_putnbr_fd(int n, int fd);
int				ft_putlong_fd(t_long n, int fd);

#endif
