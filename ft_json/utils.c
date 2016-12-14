/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 23:48:27 by juloo             #+#    #+#             */
/*   Updated: 2016/12/15 00:02:44 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_json_parser.h"

t_json_token	json_parse_error(t_json_parser *p, t_sub str)
{
	p->buff.length = p->state_len;
	ft_dstradd(&p->buff, str);
	return (JSON_ERROR);
}
