/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monsieurc <monsieurc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:00:19 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/25 14:20:44 by monsieurc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "renderer.h"

int	create_trgb(unsigned char t, unsigned char r,
	unsigned char g, unsigned char b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	pixel_put(t_buffer *img, t_vector2 coord, int color)
{
	int		offset;

	offset = (roundf(coord.y) * img->l_length
			+ roundf(coord.x) * (img->bpp / 8));
	*(unsigned int *)(img->addr + offset) = color;
}

int	apply_shade(int color, float shade)
{
	int		r;
	int		g;
	int		b;

	r = (color & 0x00FF0000) >> 16;
	g = (color & 0x0000FF00) >> 8;
	b = (color & 0x000000FF);
	r = r * shade;
	g = g * shade;
	b = b * shade;
	return (create_trgb(0, r, g, b));
}

void	copy_pixel(t_win *win, t_texture *texture,
	t_vector2 coord_dst, t_vector2 coord_src, float shade)
{
	int		color;
	int		offset;

	if (!(coord_dst.x >= 0 && coord_dst.y >= 0
			&& coord_dst.x < win->width
			&& coord_dst.y < win->height))
	{
		return ;
	}
	offset = (roundf(coord_src.y) * texture->l_length
			+ roundf(coord_src.x) * (texture->bpp / 8));
    color = create_trgb(texture->addr[offset + 3], texture->addr[offset + 2],
			texture->addr[offset + 1], texture->addr[offset]);
	color = apply_shade(color, shade);
	pixel_put(win->renderer.b_back, coord_dst, color);
}

