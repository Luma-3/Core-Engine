/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:00:19 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/21 17:04:13 by antgabri         ###   ########.fr       */
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

void	copy_pixel(t_win *win, t_texture *texture,
	t_vector2 coord_dst, t_vector2 coord_src)
{
	int	color;
	int	offset;

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
	pixel_put(win->renderer.b_back, coord_dst, color);
}
