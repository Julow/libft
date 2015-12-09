/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 14:10:39 by juloo             #+#    #+#             */
/*   Updated: 2015/12/09 14:50:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

#define DEF_FLAG(NAME, FLAG, OVER)	[NAME] = {NAME, FLAG, OVER}

static const t_f_flag_def	g_flags[(uint8_t)-1] = {
	DEF_FLAG(' ', OUT_SPACE, 0),
	DEF_FLAG('-', OUT_MINUS, 0),
	DEF_FLAG('+', OUT_PLUS, 0),
	DEF_FLAG('\'', OUT_GROUP, 0),
	DEF_FLAG('^', OUT_CENTER, 0),
	DEF_FLAG('m', OUT_TOLOWER, 0),
	DEF_FLAG('M', OUT_TOUPPER, 0),
	DEF_FLAG(',', 0, 0),
	DEF_FLAG(';', 0, 0),
	DEF_FLAG(':', 0, 0),
	DEF_FLAG('_', 0, 0),
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

static const t_format_def	g_formats[(uint8_t)-1] = {
	['d'] = &format_d,
	['D'] = &format_d,
	['i'] = &format_d,
	['c'] = &format_c,
	['C'] = &format_c,
	['s'] = &format_s,
	['S'] = &format_s,
	['x'] = &format_x,
	['X'] = &format_x,
	['o'] = &format_o,
	['O'] = &format_o,
	['b'] = &format_b,
	['B'] = &format_b,
	['u'] = &format_u,
	['U'] = &format_u,
	['f'] = &format_f,
	['!'] = &format_flush,
	['n'] = &format_endl,
};

static t_bool	is_separator(char c)
{
	return (BOOL_OF(c == ',' || c == ';' ||c == ':' ||c == '_'));
}

static int		parse_flags(t_out *out, const char *format)
{
	int					len;
	t_f_flag_def const	*flag;

	len = -1;
	while (format[++len] != '\0')
	{
		flag = g_flags + (uint8_t)format[len];
		if (flag->name == '\0')
			break ;
		out->flags &= ~(flag->override);
		out->flags |= flag->mask;
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

	if (g_formats[(uint8_t)format[0]] != NULL)
		return (0);
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
	t_format_def	f;

	len = parse_flags(out, format);
	len += parse_width(out, format + len, ap);
	len += parse_precision(out, format + len, ap);
	len += parse_length(&info, format + len);
	if (format[len] == '(')
		return (exec_subformat(out, format + len + 1, ')', ap) + len + 1);
	info.format = format[len];
	f = g_formats[(uint8_t)info.format];
	if (f == NULL)
		f = &format_default;
	f(out, &info, ap);
	return (len + 1);
}
