/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 17:56:30 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/19 18:10:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/json.h"

bool		ft_json_fail(t_json_parser *p, t_sub err)
{
	p->buff.length = p->state_len;
	p->key_len = p->state_len;
	p->token = JSON_ERROR;
	ft_dstradd(&p->buff, err);
	return (false);
}

void		ft_json_parser_clear(t_json_parser *p)
{
	ft_dstrclear(&p->buff);
}
