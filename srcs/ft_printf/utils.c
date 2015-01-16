/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 19:47:13 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/16 22:47:44 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

void			add_string(t_string *out, const char *add, int len, t_opt *opt)
{
	char			*left;
	char			*center;
	char			*start;

	left = ft_strrchr(opt->flags, '-');
	center = ft_strrchr(opt->flags, '^');
	start = ft_strrchr(opt->flags, '>');
	center = (center > left && center > start) ? center : NULL;
	left = (left > center && left > start) ? left : NULL;
	start = (start > center && start > left) ? start : NULL;
	if ((left == NULL && opt->width > 0 && start == NULL) || center != NULL)
		ft_stringaddcn(out, ' ', ((center != NULL) ? (opt->width - len) / 2 :
			opt->width - len));
	else if (start != NULL)
		ft_stringaddcn(out, ' ', opt->width - out->length);
	if (ft_strrchr(opt->flags, 'M') != NULL)
		ft_stringaddupper(out, add, len);
	else if (ft_strrchr(opt->flags, 'm') != NULL)
		ft_stringaddlower(out, add, len);
	else
		ft_stringaddl(out, add, len);
	if (left != NULL || opt->width < 0 || center != NULL)
		ft_stringaddcn(out, ' ', ((center != NULL) ? (ABS(opt->width) - len)
			/ 2 : ABS(opt->width) - len));
}

void			add_nchar(t_string *out, char c, int len, t_opt *opt)
{
	char			str[len];

	ft_memset(str, c, len);
	add_string(out, str, len, opt);
}

void			pad_preci(t_string *str, int start, t_opt *opt)
{
	if (HASF('0') && !HASF('-'))
		while (str->length < opt->width)
			ft_stringinsc(str, '0', start);
	while (str->length < opt->preci + start)
		ft_stringinsc(str, '0', start);
	while (str->length < -opt->preci)
		ft_stringaddc(str, ' ');
}

t_bool			is_separator(char c)
{
	return ((c == ',' || c == ';' || c == ':' || c == '_') ? true : false);
}

void			clear_dis(t_opt *opt)
{
	int				i;

	i = -1;
	while (opt->flags[++i] != '\0')
		if (ft_strchr(opt->format->disabled, opt->flags[i]))
			opt->flags[i] = ';';
}
