/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_meta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 11:59:10 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 11:35:03 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_internal.h"

t_meta			g_metas[] = {
	{"reset", "\033[0;0m"},
	{"eoc", "\033[39m"},
	{"eobg", "\033[49m"},
/*
** Text formats
*/
	{"bold", "\033[1m"},
	{"dim", "\033[2m"},
	{"underline", "\033[4m"},
	{"blink", "\033[5m"},
	{"invert", "\033[7m"},
	{"hide", "\033[8m"},
/*
** Text colors
*/
	{"black", "\033[30m"}, {"white", "\033[97m"},
	{"red", "\033[31m"}, {"red2", "\033[91m"},
	{"green", "\033[32m"}, {"green2", "\033[92m"},
	{"yellow", "\033[33m"}, {"yellow2", "\033[93m"},
	{"blue", "\033[34m"}, {"blue2", "\033[94m"},
	{"magenta", "\033[35m"}, {"magenta2", "\033[95m"},
	{"cyan", "\033[36m"}, {"cyan2", "\033[96m"},
	{"light", "\033[37m"}, {"dark", "\033[90m"},
	{"gray", "\033[37m"}, {"gray2", "\033[90m"},
/*
** Background colors
*/
	{"bg black", "\033[40m"}, {"bg black", "\033[107m"},
	{"bg red", "\033[41m"}, {"bg red2", "\033[101m"},
	{"bg green", "\033[42m"}, {"bg green2", "\033[102m"},
	{"bg yellow", "\033[43m"}, {"bg yellow2", "\033[103m"},
	{"bg blue", "\033[44m"}, {"bg blue2", "\033[104m"},
	{"bg magenta", "\033[45m"}, {"bg magenta2", "\033[105m"},
	{"bg cyan", "\033[46m"}, {"bg cyan2", "\033[106m"},
	{"bg light", "\033[47m"}, {"bg dark", "\033[100m"},
	{"bg gray", "\033[47m"}, {"bg gray2", "\033[100m"},
/*
** Minecraft colors
*/
	{"0", "\033[30m"},
	{"1", "\033[34m"},
	{"2", "\033[32m"},
	{"3", "\033[36m"},
	{"4", "\033[31m"},
	{"5", "\033[35m"},
	{"6", "\033[33m"},
	{"7", "\033[37m"},
	{"8", "\033[90m"},
	{"9", "\033[94m"},
	{"a", "\033[92m"},
	{"b", "\033[96m"},
	{"c", "\033[91m"},
	{"d", "\033[95m"},
	{"e", "\033[93m"},
	{"f", "\033[97m"},
/*
** Minecraft formats
*/
	{"l", "\033[1m"},
	{"n", "\033[4m"},
	{"o", "\033[2m"},
	{"r", "\033[0;0m"},
	{NULL, NULL},
};

int				parse_meta(t_string *out, const char *format)
{
	int				i;
	int				length;

	length = 0;
	while (format[length] != '}' && format[length] != '\0')
		length++;
	i = -1;
	while (g_metas[++i].name != NULL)
	{
		if (ft_strnequ(format, g_metas[i].name, length))
		{
			ft_stringaddl(out, g_metas[i].value, ft_strlen(g_metas[i].value));
			return (length + 1);
		}
	}
	ft_stringaddc(out, '{');
	return (0);
}
