/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:19:15 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/28 13:32:45 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "object.h"
#include "renderer.h"

static t_vector2	cal_dst(t_vector2 angle, t_vector2 offset, t_vector2 coord)
{
	t_vector2	dst;

	dst.x = (offset.x * angle.x - offset.y * angle.y) + coord.x;
	dst.y = (offset.x * angle.y + offset.y * angle.x) + coord.y;
	return (dst);
}

void	basic_draw2d(void *self)
{
	t_vector2	src;
	t_vector2	offset;
	t_vector2	angle;
	t_vector2	coord;
	t_render2d	*this;

	this = (t_render2d *)self;
	angle = vector2(cos(this->trans->rot.x), sin(this->trans->rot.x));
	coord = world_to_screen(this->trans->pos, this->id_win);
	src.y = 0;
	while (src.y < this->texture->size.y)
	{
		src.x = 0;
		offset.y = (src.y - (this->texture->size.y / 2)) * this->trans->scale.x;
		while (src.x < this->texture->size.x)
		{
			offset.x = (src.x - (this->texture->size.x / 2))
				* this->trans->scale.x;
			pixel_put(__get_engine()->win[this->id_win],
				cal_dst(angle, offset, vector2(coord.x, coord.y)),
				take_pixel(this->texture, src));
			src.x++;
		}
		src.y++;
	}
}
