/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 12:47:36 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/11 16:06:39 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_H
# define GL_H

# ifdef MAC_OS_MODE
#  define GLFW_INCLUDE_GLCOREARB
# else
#  include <GL/glew.h>
# endif

# include <GLFW/glfw3.h>

#endif
