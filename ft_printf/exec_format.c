/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 14:10:39 by juloo             #+#    #+#             */
/*   Updated: 2015/11/27 23:45:40 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

static const t_f_flag_def	g_flags[] = {
	{' ', OUT_SPACE, 0},
	{'-', OUT_MINUS, OUT_CENTER},
	{'+', OUT_PLUS, 0},
	{'\'', OUT_GROUP, 0},
	{'^', OUT_CENTER, OUT_MINUS},
	{'m', OUT_TOLOWER, 0},
	{'M', OUT_TOUPPER, 0},
	{'\0', 0, 0}
};

static const t_f_len_def	g_lengths[] = {
	{SUBC("hh"), f_length_hh},
	{SUBC("h"), f_length_h},
	{SUBC("ll"), f_length_ll},
	{SUBC("l"), f_length_l},
	{SUBC("j"), f_length_j},
	{SUBC("t"), f_length_t},
	{SUBC("z"), f_length_z},
	{SUBC("q"), f_length_q},
	{SUBC(""), f_length_def}
};

static const t_format_def	g_formats[] = {
	{'d', &format_d},
	{'D', &format_d},
	{'i', &format_d},
	{'c', &format_c},
	{'C', &format_c},
	{'s', &format_s},
	{'S', &format_s},
	{'x', &format_x},
	{'X', &format_x},
	{'o', &format_o},
	{'O', &format_o},
	{'b', &format_b},
	{'B', &format_b},
	{'u', &format_u},
	{'U', &format_u},
	{'f', &format_f},
	{'!', &format_flush},
	{'n', &format_endl},
	{'\0', &format_default}
};

static t_bool	is_separator(char c)
{
	return (BOOL_OF(c == ',' || c == ';' ||c == ':' ||c == '_'));
}

static int		parse_flags(t_out *out, const char *format)
{
	int				len;
	int				i;

	out->flags = 0;
	len = -1;
	while (format[++len] != '\0')
	{
		if (is_separator(format[len]))
			continue ;
		i = -1;
		while (g_flags[++i].name != '\0')
			if (g_flags[i].name == format[len])
			{
				out->flags &= ~(g_flags[i].override);
				out->flags |= g_flags[i].mask;
				break ;
			}
		if (g_flags[i].name == '\0')
			break ;
	}
	return (len);
}

static int		parse_width(t_out *out, const char *f, va_list *ap)
{
	int				len;
	int				width;

	len = 0;
	if (IS(*f, IS_DIGIT))
		len += ft_atoib(f, &width);
	else if (*f == '*' && ++len)
		width = (int)(va_arg(*ap, int));
	else
		width = 0;
	out->width = width;
	while (is_separator(f[len]))
		len++;
	return (len);
}

static int		parse_precision(t_out *out, const char *f, va_list *ap)
{
	int				len;
	int				preci;

	if (*f != '.')
		return ((out->precision = 0));
	len = 1;
	if (IS(f[len], IS_DIGIT))
		len += ft_atoib(f + len, &preci);
	else if (f[len] == '*' && ++len)
		preci = (int)(va_arg(*ap, int));
	else
		preci = 0;
	out->precision = (preci < 0) ? 0 : (uint8_t)preci;
	while (is_separator(f[len]))
		len++;
	return (len);
}

static int		parse_length(t_f_info *info, const char *format)
{
	int				i;

	i = 0;
	while (ft_memcmp(format, g_lengths[i].name.str,
			g_lengths[i].name.length) != 0)
		i++;
	info->length = g_lengths[i].length;
	i = g_lengths[i].name.length;
	while (is_separator(format[i]))
		i++;
	return (i);
}

int				exec_format(t_out *out, char const *format, va_list *ap)
{
	int				len;
	t_f_info		info;
	uint32_t		i;

	len = parse_flags(out, format);
	len += parse_width(out, format + len, ap);
	len += parse_precision(out, format + len, ap);
	len += parse_length(&info, format + len);
	info.format = format[len];
	i = 0;
	while (g_formats[i].name != '\0' && g_formats[i].name != info.format)
		i++;
	g_formats[i].f(out, &info, ap);
	return (len + 1);
}
