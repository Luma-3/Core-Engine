/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:19:15 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/15 16:38:35 by antgabri         ###   ########.fr       */
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
	t_engine	*engine;
	t_vector2	dst;
	t_vector2	src;
	t_vector2	offset;
	t_vector2	angle;
	t_vector2	coord;

	t_render2d *this = (t_render2d *)self;
	angle.x = cos(this->trans->rot.x);
	angle.y = sin(this->trans->rot.x);
	engine = get_engine();
	coord = world_to_screen(this->trans->pos, this->id_win);
	src.y = 0;
	while (src.y < this->size.y)
	{
		src.x = 0;
		offset.y = (src.y - (this->size.y / 2)) * this->trans->scale.x;
		while (src.x < this->size.x)
		{
			offset.x = (src.x - (this->size.x / 2)) * this->trans->scale.x;
			dst = cal_dst(angle, offset, vector2(coord.x, coord.y));
			if (dst.x >= 0 && dst.y >= 0 && dst.x < engine->win[this->id_win]->renderer.b_front->size.x
				&& dst.y < engine->win[this->id_win]->renderer.b_front->size.y)
			{
				copy_pixel(engine->win[this->id_win]->renderer.b_back, this, dst, src);
			}
			src.x++;
		}
		src.y++;
	}
}

