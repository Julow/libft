/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftout.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 18:28:26 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/11 19:07:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTOUT_H
# define FTOUT_H

# include "libft.h"

# define FTOUT		(&g_ftout)

/*
** function		params					action
** ->i			int						print int
** ->u			t_uint					print t_uint
** ->il			t_long					print t_long
** ->ul			t_ulong					print t_ulong
** ->c			char					print char
** ->cn			char, int				print char 'n' times
** ->n			-						print '\n' and flush
** ->z			-						print '\0' and flush
** ->s			char*					print string
** ->sl			char*, int				print 'len' chars from 'str'
** ->b			t_uint, char*			print t_uint in 'base'
** ->bl			t_ulong, char*			print t_ulong in 'base'
** ->p			void*					print ptr in hexa
** ->m			void*, t_uint			print memory
** ->f			-						flush the buffer
*/

# define FTOUT_BUFF		512

typedef struct	s_ftout
{
	int				fd;
	char			buff[FTOUT_BUFF];
	t_uint			buff_len;
/*
	struct s_ftout	*(*i)(int n);
	struct s_ftout	*(*u)(t_uint n);
	struct s_ftout	*(*il)(t_long n);
	struct s_ftout	*(*ul)(t_ulong n);
	struct s_ftout	*(*c)(char c);
	struct s_ftout	*(*sl)(const char *str, t_uint len);
	struct s_ftout	*(*s)(const char *str);
	struct s_ftout	*(*n)();
*/
}				t_ftout;

void			ft_out_add(const char *str, t_uint len);
void			ft_out_add_c(char c);
void			ft_out_flush();

t_ftout			*ft_out_i(int n);
t_ftout			*ft_out_u(t_uint n);
t_ftout			*ft_out_l(t_long n);
t_ftout			*ft_out_ul(t_ulong n);
t_ftout			*ft_out_c(char c);
t_ftout			*ft_out_cn(char c, t_uint n);
t_ftout			*ft_out_sl(const char *str, t_uint len);
t_ftout			*ft_out_s(const char *str);
t_ftout			*ft_out_n();
t_ftout			*ft_out_z();
t_ftout			*ft_out_f();

#endif
