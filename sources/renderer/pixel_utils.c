/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:23:21 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/03 13:14:24 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "renderer.h"

int	create_trgb(unsigned char t, unsigned char r,
	unsigned char g, unsigned char b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	pixel_put(t_win *win, t_vector2 coord, int color)
{
	int				offset;
	t_buffer		*buffer;

	buffer = win->renderer.b_back;
	if (!(coord.x >= 0
			&& coord.y >= 0
			&& coord.x < win->width
			&& coord.y < win->height
		))
	{
		return ;
	}
	offset = (roundf(coord.y) * buffer->l_length
			+ roundf(coord.x) * (buffer->bpp / 8));
	*(unsigned int *)(buffer->addr + offset) = color;
}

int	apply_shade(int color, float shade)
{
	int		r;
	int		g;
	int		b;
	int		t;

	t = ((color & 0xFF000000) >> 24);
	r = ((color & 0x00FF0000) >> 16) * shade;
	g = ((color & 0x0000FF00) >> 8) * shade;
	b = (color & 0x000000FF) * shade;
	return (create_trgb(t, r, g, b));
}

int	take_pixel(t_texture *texture, t_vector2 coord)
{
	int	color;
	int	offset;

	offset = ((int)(coord.y) *(texture->l_length)
			+ (int)(coord.x) *(texture->bpp / 8));
	color = create_trgb(
			texture->addr[offset + 3],
			texture->addr[offset + 2],
			texture->addr[offset + 1],
			texture->addr[offset]
			);
	return (color);
}
