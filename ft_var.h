/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 00:49:06 by juloo             #+#    #+#             */
/*   Updated: 2015/09/11 00:23:10 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VAR_H
# define FT_VAR_H

# include <stdarg.h>

/*
** ========================================================================== **
** Variadic
** -
** Wrap builtin va_list + variadic struct
*/

typedef struct	s_var_strct
{
	void			*data;
	int				curr;
}				t_var_strct;

typedef enum	e_var_type
{
	var_t_arg,
	var_t_strct
}				t_var_type;

typedef union	u_var_data
{
	va_list			a;
	t_var_strct		s;
}				t_var_data;

typedef struct	s_var
{
	t_var_type		t;
	t_var_data		data;
}				t_var;

/*
** VAR_INIT
** -
** Init a variadic
** VAR_INIT_A(v, param)		Call va_start
** VAR_INIT_S(v, ptr)		Create a struct variadic
*/
# define VAR_INIT_A(v,p)	((v)=(t_var){.t=var_t_arg});va_start((v).data.a,p)
# define VAR_INIT_S(v,p)	((v)=(t_var){var_t_strct,{.s=(t_var_strct){(p),0}}})

/*
** VAR_GET
** -
** Get a var
** 'v' is a t_var
*/
# define VAR_GET(v,t)		(VAR_IS_VA(v)?va_arg((v).data.a,t):VAR_S_GET(v,t))

/*
** VAR_END
** -
** End a var
*/
# define VAR_END(v)			(VAR_IS_VA(v)?va_end((v).data.a):(void)(v))

/*
** internal
*/
# define VAR_IS_VA(v)		((v).t==var_t_arg)
# define VAR_S_GET(v,t)		*((t*)ft_varget(&((v).data.s), sizeof(t)))

static inline void	*ft_varget(t_var_strct *v, int size)
{
	void *const		tmp = v->data + v->curr;

	v->curr += (size - ((v->curr + size) % size)) % size + size;
	return (tmp);
}

#endif
