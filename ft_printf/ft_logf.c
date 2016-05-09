/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 14:40:49 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/09 18:44:10 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_colors.h"
#include "printf_internal.h"

#define DEBUG_PREFIX	(C_LCYAN "[" C_RESET "Debug" C_LCYAN "]" C_RESET " ")
#define VERBOSE_PREFIX	(C_CYAN "[Verbose]" C_RESET " ")
#define INFO_PREFIX		(C_CYAN "[Info]" C_RESET " ")
#define SUCCESS_PREFIX	(C_GREEN "[Success]" C_RESET " ")
#define WARNING_PREFIX	(C_YELLOW "[Warning]" C_RESET " ")
#define ERROR_PREFIX	(C_RED "[Error]" C_RESET " ")

static t_log_info	g_log_info[] = {
	[LOG_DEBUG] = {SUBC(DEBUG_PREFIX), 1, false},
	[LOG_VERBOSE] = {SUBC(VERBOSE_PREFIX), 1, false},
	[LOG_INFO] = {SUBC(INFO_PREFIX), 1, true},
	[LOG_SUCCESS] = {SUBC(SUCCESS_PREFIX), 1, true},
	[LOG_WARNING] = {SUBC(WARNING_PREFIX), 2, true},
	[LOG_ERROR] = {SUBC(ERROR_PREFIX), 2, true}
};

void			ft_logf(t_log_level level, char const *format, ...)
{
	va_list			ap;
	int const		old_fd = g_ftout.fd;

	if (!g_log_info[level].enabled)
		return ;
	ft_out(g_log_info[level].fd);
	ft_putsub(FTOUT, g_log_info[level].prefix);
	va_start(ap, format);
	ft_putf(FTOUT, format, &ap);
	va_end(ap);
	ft_putendl(FTOUT);
	ft_out(old_fd);
}

void			ft_logf_set_enabled(t_log_level level, bool enabled)
{
	g_log_info[level].enabled = enabled;
}
