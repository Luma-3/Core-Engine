/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:19:15 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/10 15:56:56 by jbrousse         ###   ########.fr       */
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

void	basic_draw2d(t_render2d *this)
{
	t_mrender	*renderer;
	t_vector2	dst;
	t_vector2	src;
	t_vector2	offset;
	t_vector2	angle;

	angle.x = cos(this->trans->rot.x);
	angle.y = sin(this->trans->rot.x);
	renderer = get_renderer();
	dst.y = 0;
	while (src.y < this->size.y)
	{
		dst.x = 0;
		offset.y = (src.y - (this->size.y / 2)) * this->trans->scale.y;
		while (src.x < this->size.x)
		{
			offset.x = (src.x - (this->size.x / 2)) * this->trans->scale.x;
			dst = cal_dst(angle, offset, this->trans->pos);
			if (dst.x >= 0 && dst.y >= 0 && dst.x < renderer->b_front->size.x
				&& dst.y < renderer->b_front->size.y)
				copy_pixel(renderer->b_front, this, dst, src);
			src.x++;
		}
		src.y++;
	}
}

// void	render_2d(t_render2d *buffer)
// {
// 	t_engine	*engine;
// 	t_vector2	coord;
// 	size_t		index;

// 	engine = get_engine();
// 	index = 0;
// 	while (index < OBJ_2D_MAX)
// 	{
// 		if (engine->object_2d[index] != NULL)
// 		{
// 			coord = world_to_screen(engine->object_2d[index]->coord);
// 			if (!culling_obj(coord.x, coord.y,
// 					engine->object_2d[index]->render.size.x,
// 					engine->object_2d[index]->render.size.y))
// 			{
// 				draw_obj_to_frame(buffer, engine->object_2d[index],
//				 &coord, engine->object_2d[index]->angle);
// 			}
// 		}
// 		index++;
// 	}
// }
