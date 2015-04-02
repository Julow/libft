/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 13:51:27 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/03 01:41:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

const t_pfflag	g_flags[] = {
	{'#', PFLAG_ALT, 0},
	{' ', PFLAG_SPACE, 0},
	{'0', PFLAG_ZERO, 0},
	{'-', PFLAG_MOINS, PFLAG_CENTER | PFLAG_RIGHT},
	{'+', PFLAG_PLUS, 0},
	{'\'', PFLAG_GROUP, 0},
	{'^', PFLAG_CENTER, PFLAG_MOINS | PFLAG_RIGHT},
	{'>', PFLAG_RIGHT, PFLAG_MOINS | PFLAG_CENTER},
	{'m', PFLAG_LOWER, PFLAG_UPPER},
	{'M', PFLAG_UPPER, PFLAG_LOWER},
	{'\0', 0, 0}
};

const t_pflen	g_lengths[] = {
	{"hh", pflen_hh},
	{"h", pflen_h},
	{"ll", pflen_ll},
	{"l", pflen_l},
	{"L", pflen_L},
	{"j", pflen_j},
	{"t", pflen_t},
	{"I", pflen_I},
	{"z", pflen_z},
	{"q", pflen_q},
	{NULL, pflen_def}
};

const t_pformat	g_formats[] = {
	{'d', &flag_d},
	{'D', &flag_d},
	{'i', &flag_d},
	{'c', &flag_c},
	{'C', &flag_c},
	{'%', &flag_percent},
	{'s', &flag_s},
	{'S', &flag_s},
	{'n', &flag_n},
	{'x', &flag_x},
	{'X', &flag_x},
	{'o', &flag_o},
	{'O', &flag_o},
	{'b', &flag_b},
	{'B', &flag_b},
	{'p', &flag_p},
	{'P', &flag_p},
	{'u', &flag_u},
	{'U', &flag_u},
	{'r', &flag_r},
	{'\0', NULL}
};

static int		parse_flags(t_pfopt *opt, const char *format)
{
	int				len;
	int				i;

	opt->flags = 0;
	len = -1;
	while (format[++len] != '\0')
	{
		if (is_separator(format[len]))
			continue ;
		i = -1;
		while (g_flags[++i].name != '\0')
			if (g_flags[i].name == format[len])
			{
				opt->flags &= ~(g_flags[i].override);
				opt->flags |= g_flags[i].mask;
				break ;
			}
		if (g_flags[i].name == '\0')
			break ;
	}
	return (len);
}

static int		parse_width(t_printf *pf, t_pfopt *opt, const char *f)
{
	int				len;

	len = 0;
	if (ft_isdigit(*f))
		len += ft_atoib(f, &(opt->width));
	else if (*f == '*' && ++len)
		opt->width = (int)(va_arg(*(pf->ap), int));
	else
		opt->width = 0;
	while (is_separator(f[len]))
		len++;
	return (len);
}

static int		parse_precision(t_printf *pf, t_pfopt *opt, const char *f)
{
	int				len;

	if (*f != '.')
		return ((opt->preci = 0), 0);
	len = 1;
	if (ft_isdigit(f[len]))
		len += ft_atoib(f + len, &(opt->preci));
	else if (f[len] == '*' && ++len)
		opt->preci = (int)(va_arg(*(pf->ap), int));
	opt->flags |= PFLAG_PRECI;
	while (is_separator(f[len]))
		len++;
	return (len);
}

static int		parse_length(t_pfopt *opt, const char *format)
{
	int				i;
	int				len;

	i = -1;
	len = 0;
	while (g_lengths[++i].name != NULL)
	{
		len = ft_strlen(g_lengths[i].name);
		if (ft_strnequ(format, g_lengths[i].name, len))
			break ;
		len = 0;
	}
	opt->length = g_lengths[i].length;
	while (is_separator(format[len]))
		len++;
	return (len);
}

int				parse_format(t_printf *pf, const char *format)
{
	int				len;
	t_pfopt			opt;
	int				i;

	len = parse_flags(&opt, format);
	len += parse_width(pf, &opt, format + len);
	len += parse_precision(pf, &opt, format + len);
	len += parse_length(&opt, format + len);
	if (format[len] == '\0')
		return (0);
	if (format[len] == '{')
		return (parse_meta(pf, &opt, format + (++len)) + len);
	i = -1;
	while (g_formats[++i].name != '\0')
		if (g_formats[i].name == format[len])
		{
			opt.format = format[len];
			g_formats[i].f(pf, &opt);
			break ;
		}
	if (g_formats[i].name == '\0')
		flag_other(pf, &opt, format[len]);
	return (len + 1);
}
