/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 14:10:39 by juloo             #+#    #+#             */
/*   Updated: 2016/01/03 14:12:06 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

static const uint32_t		g_flags[(uint8_t)-1] = {
	[' '] = OUT_SPACE,
	['-'] = OUT_MINUS,
	['+'] = OUT_PLUS,
	['\''] = OUT_GROUP,
	['^'] = OUT_CENTER,
	['m'] = OUT_TOLOWER,
	['M'] = OUT_TOUPPER,
	['#'] = PRINTF_F_ALT,
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

static int		parse_flags(t_out *out, const char *format)
{
	int				len;
	uint32_t		flag;

	len = -1;
	while (format[++len] != '\0')
	{
		flag = g_flags[(uint8_t)format[len]];
		if (flag == 0)
			break ;
		out->flags |= flag;
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
	info.length = f_length_def;
	if (g_formats[(uint8_t)format[len]] == NULL)
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
