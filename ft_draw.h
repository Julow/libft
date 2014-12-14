/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 18:21:42 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/13 18:21:43 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DRAW_H
# define FT_DRAW_H

# include "libft.h"

# define MIN(a,b)	(((a) < (b)) ? (a) : (b))
# define MAX(a,b)	(((a) > (b)) ? (a) : (b))
# define ABS(a)		(((a) < 0) ? -(a) : (a))

# define PT(x,y)	((t_pt){(x), (y)})
# define POS(x,y,z)	((t_pos){(x), (y), (z)})

# define UP(n)		((int)(1 + (n)))
# define ROUND(n)	((int)(0.5 + (n)))
# define DOWN(n)	((int)(n))

typedef struct	s_image
{
	char			*data;
	void			*img;
	int				width;
	int				height;
	int				l_size;
	int				opp;
	int				endian;
}				t_image;

typedef union	u_color
{
	struct			s_color
	{
		t_uchar			b;
		t_uchar			g;
		t_uchar			r;
		t_uchar			a;
	}				b;
	t_uint			i;
}				t_color;

typedef struct	s_pt
{
	int				x;
	int				y;
}				t_pt;

typedef struct	s_pos
{
	double			x;
	double			y;
	double			z;
}				t_pos;

void			ft_imageclr(t_image *img);

void			ft_resrect(t_pt *p1, t_pt *p2);

void			ft_drawxy(t_image *img, int x, int y, t_color color);
void			ft_drawpt(t_image *img, t_pt pt, t_color color);
void			ft_drawnpt(t_image *img, t_pt pt, int n, t_color color);

void			ft_drawrect(t_image *img, t_pt p1, t_pt p2, t_color color);
void			ft_drawrectf(t_image *img, t_pt p1, t_pt p2, t_color color);
void			ft_drawcircle(t_image *img, t_pt o, int radius, t_color color);
void			ft_drawcirclef(t_image *img, t_pt o, int radius, t_color color);

void			ft_drawline(t_image *img, t_pt p1, t_pt p2, t_color color);

#endif
