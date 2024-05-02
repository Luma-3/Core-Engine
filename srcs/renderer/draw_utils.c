/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:00:19 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/02 15:44:44 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_engine.h"
#include "render.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// interpolation for hole in the object when rotating

// Anti-aliasing for object rendering

void	pixel_put(t_img *img, t_coord *coord, int color)
{
	int		offset;

	offset = (roundf(coord->y) * img->l_length
			+ roundf(coord->x) * (img->bpp / 8));
	*(unsigned int *)(img->addr + offset) = color;
}

void	copy_pixel(t_img *dst, t_img *src, t_coord *dst_c, t_coord *src_c)
{
	int	color;
	int	offset;

	offset = (roundf(src_c->y) * src->l_length
			+ roundf(src_c->x) * (src->bpp / 8));
	color = create_trgb(src->addr[offset + 3], src->addr[offset + 2],
			src->addr[offset + 1], src->addr[offset]);
	pixel_put(dst, dst_c, color);
}
