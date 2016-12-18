/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_json_t.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 14:24:24 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/18 14:58:17 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_JSON_T_H
# define P_JSON_T_H

# include "ft/json_t.h"

/*
** ========================================================================== **
*/

extern bool	(*const g_json_t_parse[])(t_json_parser*,
				t_json_t_value const*, void*);
extern void	(*const g_json_t_free[])(t_json_t_value const*, void*);

bool		json_t_parse_string(t_json_parser *p,
				t_json_t_value const *t, void *data);
bool		json_t_parse_int(t_json_parser *p,
				t_json_t_value const *t, void *data);
bool		json_t_parse_float(t_json_parser *p,
				t_json_t_value const *t, void *data);
bool		json_t_parse_bool(t_json_parser *p,
				t_json_t_value const *t, void *data);
bool		json_t_parse_callback(t_json_parser *p,
				t_json_t_value const *t, void *data);
bool		json_t_parse_dict(t_json_parser *p,
				t_json_t_value const *t, void *data);
bool		json_t_parse_list(t_json_parser *p,
				t_json_t_value const *t, void *data);

#endif
