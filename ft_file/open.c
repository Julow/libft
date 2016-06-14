/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 19:07:32 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/14 19:09:34 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/file.h"

#include <fcntl.h>
#include <unistd.h>

int				ft_open(t_sub file, uint32_t o_flags)
{
	char			file_name[file.length + 1];

	ft_memcpy(file_name, file.str, file.length);
	file_name[file.length] = '\0';
	return (open(file_name, o_flags, 0644));
}
