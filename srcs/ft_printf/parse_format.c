/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 11:29:03 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/16 22:50:57 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"
#include <stdlib.h>

/*
** sSdDioOuUxXcCnpeEfFbBrRgG
** %%
** 0, ,-,+,#,^,',>,m,M
** width,*
** precision,*
** hh,h,ll,l,L,j,t,z,q
** =============
** =============
** $
** aA
** k
*/
t_format		g_formats[] = {
	{'%', &flag_percent, "0"},
	{'s', &flag_s, "0"},
	{'S', &flag_s, "0"},
	{'d', &flag_d, ""},
	{'D', &flag_d, ""},
	{'i', &flag_d, ""},
	{'o', &flag_o, "+"},
	{'O', &flag_o, "+"},
	{'u', &flag_u, "+"},
	{'U', &flag_u, "+"},
	{'x', &flag_x, "+"},
	{'X', &flag_x, "+"},
	{'c', &flag_c, ""},
	{'C', &flag_c, ""},
	{'n', &flag_n, ""},
	{'p', &flag_p, ""},
	{'e', &flag_e, ""},
	{'E', &flag_e, ""},
	{'f', &flag_f, ""},
	{'F', &flag_f, ""},
	{'b', &flag_b, "+"},
	{'B', &flag_b, "+"},
	{'r', &flag_r, "+"},
	{'\0', NULL, NULL}
};

char			*g_lengths[] = {
	"I32",
	"hh",
	"h",
	"ll",
	"l",
	"L",
	"j",
	"t",
	"I",
	"z",
	"q",
	"I64",
	NULL
};

static int		parse_flags(t_opt *opt, const char *format)
{
	int				i;

	i = 0;
	while (format[i] == '#' || format[i] == ' ' || format[i] == '0'
		|| format[i] == '-' || format[i] == '+' || format[i] == '\''
		|| format[i] == '^' || format[i] == '>' || format[i] == 'm'
		|| format[i] == 'M' || is_separator(format[i]))
		i++;
	opt->flags = ft_strsub(format, 0, i);
	return (i);
}

static int		parse_width(t_opt *opt, const char *format, va_list *ap)
{
	int				length;

	opt->width = 0;
	length = 0;
	while (ft_isdigit(format[length]))
		length++;
	if (length > 0)
		opt->width = ft_atoin(format, length);
	if (format[length] == '*')
	{
		opt->width = (int)(va_arg(*ap, int));
		length++;
	}
	while (is_separator(format[length]))
		length++;
	return (length);
}

static int		parse_precision(t_opt *opt, const char *format, va_list *ap)
{
	int				length;

	if (*format != '.')
		return (opt->preci_set = false,
		opt->preci = 0, 0);
	length = 1;
	while (format[length] == '.')
		length++;
	if (format[length] == '*')
	{
		opt->preci = (int)(va_arg(*ap, int));
		length++;
	}
	else
	{
		while (format[length] == '-')
			length++;
		opt->preci = ft_atoi(format + length - ((format[length - 1] == '-')
			? 1 : 0));
		while (ft_isdigit(format[length]))
			length++;
	}
	while (is_separator(format[length]))
		length++;
	return (opt->preci_set = true, length);
}

static int		parse_length(t_opt *opt, const char *format)
{
	int				i;
	int				len;

	i = -1;
	while (g_lengths[++i] != NULL)
	{
		len = ft_strlen(g_lengths[i]);
		if (ft_strnequ(g_lengths[i], format, len))
		{
			opt->length = g_lengths[i];
			while (is_separator(format[len]))
				len++;
			return (len);
		}
	}
	opt->length = "";
	return (0);
}

int				parse_format(t_string *out, const char *format, va_list *ap)
{
	int				length;
	int				i;
	t_opt			opt;

	length = 0;
	length += parse_flags(&opt, format + length);
	length += parse_width(&opt, format + length, ap);
	length += parse_precision(&opt, format + length, ap);
	length += parse_length(&opt, format + length);
	i = -1;
	while (g_formats[++i].name != '\0')
	{
		if (g_formats[i].name == format[length])
		{
			opt.format = g_formats + i;
			clear_dis(&opt);
			g_formats[i].func(out, &opt, ap);
			return (free(opt.flags), length + 1);
		}
	}
	if (format[length] != '\0')
		add_string(out, format + (length++), 1, &opt);
	return (free(opt.flags), length);
}
