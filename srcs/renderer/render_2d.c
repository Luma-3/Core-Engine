/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:19:15 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/29 17:32:49 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_engine.h"
#include "coord.h"
#include "object.h"
#include "render.h"

static void	draw_obj_to_frame(t_img *img, t_img *buffer, t_coord *obj_s_coord)
{
	t_coord	coord_root;
	t_coord dst_coord;
	t_coord src_coord;

	coord_root.x = obj_s_coord->x;
	coord_root.y= obj_s_coord->y;
	while (obj_s_coord->y < img->width + coord_root.y)
	{
		obj_s_coord->x = coord_root.x;
		while (obj_s_coord->x < img->height + coord_root.x)
		{
			src_coord.x = obj_s_coord->x - coord_root.x;
			src_coord.y = obj_s_coord->y - coord_root.y;
			dst_coord.x = obj_s_coord->x - (img->width / 2);
			dst_coord.y = obj_s_coord->y - (img->height / 2);
			if (dst_coord.x >= 0 && dst_coord.y >= 0 && dst_coord.x < buffer->width && dst_coord.y < buffer->height)
				copy_pixel(buffer, img, &dst_coord, &src_coord);
			obj_s_coord->x++;
		}
		obj_s_coord->y++;
	}
}

static bool	culling_obj(int	x, int y, int width, int height)
{
	t_engine	*engine;

	engine = get_engine();
	if (x - (width / 2) > engine->width || x + (width / 2) < 0)
	{
		return (true);
	}
	if (y - (height / 2) > engine->height || y + (height / 2) < 0)
	{
		return (true);
	}
	return (false);
}

void	render_2d(t_img *buffer)
{
	t_engine *engine;
	t_coord	*coord;
	size_t index;

	engine = get_engine();
	index = 0;
	while (index < OBJ_2D_MAX)
	{
		if (engine->object_2d[index] != NULL)
		{
			coord = world_to_screen(engine->object_2d[index]->coord);
			if (culling_obj(coord->x, coord->y, engine->object_2d[index]->img->width, engine->object_2d[index]->img->height) == false)
			{
				draw_obj_to_frame(engine->object_2d[index]->img, buffer, coord);
			}
			free_coord(coord);
		}
		index++;
	}
}