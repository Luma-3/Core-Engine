/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:00:19 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/15 15:47:19 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "renderer.h"

int	create_trgb(int t, int r, int g, int b)
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

void	copy_pixel(t_buffer *dst, t_render2d *src,
	t_vector2 dst_c, t_vector2 src_c)
{
	int	color;
	int	offset;

	offset = (roundf(src_c.y) * src->l_length
			+ roundf(src_c.x) * (src->bpp / 8));
	color = create_trgb(src->addr[offset + 3], src->addr[offset + 2],
			src->addr[offset + 1], src->addr[offset]);
	pixel_put(dst, dst_c, color);
}
