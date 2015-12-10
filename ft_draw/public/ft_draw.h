/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 16:48:15 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:20:39 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DRAW_H
# define FT_DRAW_H

# include "ft/libft.h"

/*
** ========================================================================== **
** Math 2d
*/

# define PT(x,y)		((t_pt){(x), (y)})
# define POS(x,y,z)		((t_pos){(x), (y), (z)})
# define RECT(x,y,w,h)	((t_rect){(x), (y), (w), (h)})

# define BIG(a)			((a) * 1000000)
# define BTOI(a)		((a) / 1000000)
# define MIX(a,b,p)		((a) - BTOI((a) * (p)) + BTOI((b) * (p)))

typedef long long int	t_big;

typedef struct	s_pos
{
	double			x;
	double			y;
	double			z;
}				t_pos;

typedef struct	s_pt
{
	int				x;
	int				y;
}				t_pt;

typedef struct	s_rect
{
	int				x;
	int				y;
	int				width;
	int				height;
}				t_rect;

int				ft_mix(int a, int b, t_big pos);

void			ft_resrect(t_rect *rect, t_rect bounds);

int				ft_dist2(t_pt p1, t_pt p2);

t_pt			ft_nearest(t_pt pos, t_pt p1, t_pt p2);
t_pt			ft_farthest(t_pt pos, t_pt p1, t_pt p2);

/*
** ========================================================================== **
** Draw
*/

# define C(c)			((t_color)(uint32_t)(c))
# define RGBA(r,g,b,a)	((t_color)((t_rgb){(b), (g), (r), (a)}))
# define RGB(r,g,b)		RGBA(r, g, b, 0)
# define INVI(c)		((c).u > 0xFF000000)
# define ALPHA(c)		((c).u >= 0x01000000)

# define IMAGEPOS(i,p)	*((t_color*)((void*)((i)->data + (p))))
# define IMAGEPT(i,x,y)	IMAGEPOS(i, ((i)->width * y + x) * (i)->opp)

typedef struct	s_image
{
	uint8_t			*data;
	void			*img;
	int				width;
	int				height;
	int				l_size;
	int				opp;
	int				endian;
}				t_image;

typedef struct	s_rgb
{
	uint8_t			b;
	uint8_t			g;
	uint8_t			r;
	uint8_t			a;
}				t_rgb;

typedef union	u_color
{
	t_rgb			b;
	uint32_t		u;
	int				i;
	uint8_t			t[4];
}				t_color;

void			ft_resalpha(t_color *c, t_color bg);

void			ft_imageclr(t_image *img);
void			ft_imageclrc(t_image *img, t_color color);
t_image			*ft_imageclone(t_image *img);
void			ft_imageclonekil(t_image *clone);

void			ft_drawxy(t_image *img, int x, int y, t_color color);
void			ft_drawpt(t_image *img, t_pt pt, t_color color);
void			ft_drawnpt(t_image *img, t_pt pt, int n, t_color color);
void			ft_drawvert(t_image *img, t_pt pt, int height, t_color color);

void			ft_drawimage(t_image *dst, t_image *src, t_pt pos, t_rect part);

void			ft_drawline(t_image *img, t_pt p1, t_pt p2, t_color color);
void			ft_drawrect(t_image *img, t_rect rect, t_color color);
void			ft_drawrectf(t_image *img, t_rect rect, t_color color);
void			ft_drawdiv(t_image *img, int y, int height, t_color color);
void			ft_drawcircle(t_image *img, t_pt o, int radius, t_color color);
void			ft_drawcirclef(t_image *img, t_pt o, int radius, t_color color);
void			ft_drawtri(t_image *img, t_pt pts[3], t_color color);
void			ft_drawtrif(t_image *img, t_pt pts[3], t_color color);

#endif
