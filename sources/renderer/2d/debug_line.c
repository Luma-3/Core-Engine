/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:10:05 by antgabri          #+#    #+#             */
/*   Updated: 2024/05/10 16:56:02 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_engine.h"

static bool	is_inside_square(t_vector2 point, t_vector2 start, t_vector2 end)
{
	if (point.x >= start.x && point.x <= end.x
		&& point.y <= start.y && point.y >= end.y)
	{
		return (true);
	}
	return (false);
}

static t_vector2	__cal_start_obj(t_object2d *obj)
{
	t_vector2	start_obj;
	t_engine	*engine;
	float		scale;

	scale = obj->scale;
	engine = get_engine();
	start_obj = (t_vector2){obj->coord.x - (obj->render.size.x * scale / 2),
		obj->coord.y + (obj->render.size.y * scale / 2),};
	return (start_obj);
}

static t_vector2	__cal_end_obj(t_object2d *obj)
{
	t_vector2	end_obj;
	t_engine	*engine;

	engine = get_engine();
	end_obj = (t_vector2){obj->coord.x + (obj->render.size.x * obj->scale / 2),
		obj->coord.y - (obj->render.size.y * obj->scale / 2),};
	return (end_obj);
}

static bool	verif_point(t_vector2 point, int j)
{
	t_engine	*engine;
	t_vector2	start_obj;
	t_vector2	end_obj;

	engine = get_engine();
	start_obj = __cal_start_obj(engine->object_2d[j]);
	end_obj = __cal_end_obj(engine->object_2d[j]);
	if (is_inside_square(point, start_obj, end_obj) == true)
	{
			return (true);
	}
	return (false);
}

t_vector2	next_intersection(t_vector2 player, t_vector2 wall, float distance_to_wall)
{
	t_vector2	intersection;
	float		theta;

	theta = atan2(wall.y - player.y, wall.x - player.x);
	intersection.x = player.x + distance_to_wall * cos(theta);
	intersection.y = player.y + distance_to_wall * sin(theta);
	return (intersection);
}

t_vector2	cast_ray(t_vector2 start, float angle)
{
	t_engine	*engine;
	t_vector2	point;
	t_vector2	raiser;
	float		t;
	int			j;
	int			obj_start_id;
	float		distance_to_wall;

	raiser.x = cos(angle);
	raiser.y = sin(angle);
	engine = get_engine();
	t = 0;
	obj_start_id = -2;
	while (t < 1000)
	{
		point = (t_vector2){start.x + t * raiser.x, start.y - t * raiser.y};
		j = 0;
		while (j++ < engine->nb_obj)
		{
			if (engine->object_2d[j] == NULL)
				continue ;
			else if (verif_point(point, j) == true)
			{

				if (obj_start_id == -1)
				{
					 obj_start_id = j;
				}
				else if (obj_start_id != j)
				{
					distance_to_wall = sqrt(pow(point.x - start.x, 2) + pow(point.y - start.y, 2));
				 	return (next_intersection(start, point, distance_to_wall));
				}
			}
		}
		t += 0.1;
	}
	return (point);
}

void    draw_line(int x1, int y1, int x2, int y2, t_render2d *buffer)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xIncrement = (float)dx / (float)steps;
    float yIncrement = (float)dy / (float)steps;
    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++)
    {
		if (x > 0 && x < buffer->size.x && y > 0 && y < buffer->size.y)
			pixel_put(buffer, (t_vector2){x, y}, 0xFF0000);
		else
			break ;
        x += xIncrement;
        y += yIncrement;
    }
}

void	draw_rays(t_object2d *obj, t_vector2 start, t_vector2 end)
{
	obj->d_point_start = world_to_screen(start);
	obj->d_point_end = world_to_screen(end);
}

