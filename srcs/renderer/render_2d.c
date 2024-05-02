/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:19:15 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/02 15:32:21 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_engine.h"
#include "coord.h"
#include "object.h"
#include "render.h"


static void	draw_obj_to_frame(t_img *img, t_img *buffer, t_coord *obj_coord, float cam_angle)
{
	t_coord	pixel_coord;
	t_coord pixel_offset;
	t_coord dst_coord;
	t_coord rotate_obj;

	pixel_coord.y = 0;
	while (pixel_coord.y < img->height)
	{
		pixel_coord.x = 0;
		pixel_offset.y = obj_coord->y - (img->height / 2);
		while (pixel_coord.x < img->width)
		{
			pixel_offset.x = obj_coord->x - (img->width / 2);
			rotate_obj.x = pixel_coord.x * cos(cam_angle) - pixel_coord.y * sin(cam_angle);
			rotate_obj.y = pixel_coord.x * sin(cam_angle) + pixel_coord.y * cos(cam_angle);
			dst_coord.x = pixel_offset.x + rotate_obj.x;
			dst_coord.y = pixel_offset.y - rotate_obj.y;
			if (dst_coord.x >= 0 && dst_coord.y >= 0 && dst_coord.x < buffer->width && dst_coord.y < buffer->height)
				copy_pixel(buffer, img, &dst_coord, &pixel_coord);
			pixel_coord.x++;
		}
		pixel_coord.y++;
	}
}

static bool	culling_obj(int	x, int y, int width, int height)
{
	t_engine	*engine;

	engine = get_engine();
	if (x - (width / 2) > engine->width + 1 || x + (width / 2) < -1)
	{
		return (true);
	}
	if (y - (height / 2) > engine->height + 1 || y + (height / 2) < -1)
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
			if (coord != NULL && !culling_obj(coord->x, coord->y, engine->object_2d[index]->img->width, engine->object_2d[index]->img->height))
			{
				draw_obj_to_frame(engine->object_2d[index]->img, buffer, coord, engine->camera->angle);
			}
			free_coord(coord);
		}
		index++;
	}
}