/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_meta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 00:04:36 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/03 15:47:20 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"
#include "ft_colors.h"

const t_meta	g_metas[] = {
	META_T("nl", meta_t_func, &meta_nl),
	META_T("fl", meta_t_func, &meta_fl),

	META_T("reset", meta_t_str, "\033[0;0m"),
	META_T("bold", meta_t_str, "\033[1m"),
	META_T("dim", meta_t_str, "\033[2m"),
	META_T("underline", meta_t_str, "\033[4m"),
	META_T("blink", meta_t_str, "\033[5m"),
	META_T("invert", meta_t_str, "\033[7m"),
	META_T("hide", meta_t_str, "\033[8m"),

	META_T("creset", meta_t_str, C_RESET),
	META_T("black", meta_t_str, C_BLACK),
	META_T("white", meta_t_str, C_WHITE),
	META_T("red", meta_t_str, C_RED),
	META_T("green", meta_t_str, C_GREEN),
	META_T("yellow", meta_t_str, C_YELLOW),
	META_T("blue", meta_t_str, C_BLUE),
	META_T("magenta", meta_t_str, C_MAGENTA),
	META_T("cyan", meta_t_str, C_CYAN),
	META_T("gray", meta_t_str, C_GRAY),
	META_T("lred", meta_t_str, C_LRED),
	META_T("lgreen", meta_t_str, C_LGREEN),
	META_T("lyellow", meta_t_str, C_LYELLOW),
	META_T("lblue", meta_t_str, C_LBLUE),
	META_T("lmagenta", meta_t_str, C_LMAGENTA),
	META_T("lcyan", meta_t_str, C_LCYAN),
	META_T("lgray", meta_t_str, C_LGRAY),

	META_T("bg reset", meta_t_str, BG_RESET),
	META_T("bg black", meta_t_str, BG_BLACK),
	META_T("bg white", meta_t_str, BG_WHITE),
	META_T("bg red", meta_t_str, BG_RED),
	META_T("bg green", meta_t_str, BG_GREEN),
	META_T("bg yellow", meta_t_str, BG_YELLOW),
	META_T("bg blue", meta_t_str, BG_BLUE),
	META_T("bg magenta", meta_t_str, BG_MAGENTA),
	META_T("bg cyan", meta_t_str, BG_CYAN),
	META_T("bg gray", meta_t_str, BG_GRAY),
	META_T("bg lred", meta_t_str, BG_LRED),
	META_T("bg lgreen", meta_t_str, BG_LGREEN),
	META_T("bg lyellow", meta_t_str, BG_LYELLOW),
	META_T("bg lblue", meta_t_str, BG_LBLUE),
	META_T("bg lmagenta", meta_t_str, BG_LMAGENTA),
	META_T("bg lcyan", meta_t_str, BG_LCYAN),
	META_T("bg lgray", meta_t_str, BG_LGRAY),

	META_T(NULL, meta_t_nope, NULL)
};

static void		print_meta(t_printf *pf, t_pfopt *opt, const char *str)
{
	int				len;

	len = ft_strlen(str);
	margin_before(pf, opt, len);
	ft_write(pf->out, str, len);
	pf->printed += len;
	margin_after(pf, opt, len);
}

int				parse_meta(t_printf *pf, t_pfopt *opt, const char *format)
{
	int				len;
	int				i;

	len = 0;
	while (format[len] && format[len] != '}' && !ft_isspace(format[len]))
		len++;
	i = -1;
	while (g_metas[++i].type != meta_t_nope)
		if (g_metas[i].name_len == len &&
			ft_memcmp(g_metas[i].name, format, len) == 0)
		{
			if (g_metas[i].type == meta_t_func)
				len += ((int (*)())g_metas[i].data)(pf, opt, format + len);
			else if (g_metas[i].type == meta_t_str)
				print_meta(pf, opt, g_metas[i].data);
			return ((format[len] == '}') ? len + 1 : len);
		}
	return (0);
}
