/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:19:15 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/07 17:59:53 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_engine.h"
#include "coord.h"
#include "object.h"
#include "render.h"

static bool	culling_obj(int x, int y, int width, int height)
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

void	get_min_max(t_vector2 *min, t_vector2 *max, t_triangle triangle)
{
	int	i;

	i = 0;
	*min = new_coord(triangle.coord[0].x, triangle.coord[0].y);
	*max = new_coord(triangle.coord[0].x, triangle.coord[0].y);
	while (i < 3)
	{
		if (triangle.coord[i].x < min->x)
			min->x = triangle.coord[i].x;
		if (triangle.coord[i].y < min->y)
			min->y = triangle.coord[i].y;
		if (triangle.coord[i].x > max->x)
			max->x = triangle.coord[i].x;
		if (triangle.coord[i].y > max->y)
			max->y = triangle.coord[i].y;
		i++;
	}
}

static bool	is_inside_triangle(t_vector2 coord, t_triangle triangle)
{
	t_vector2	edge[3];
	t_vector2	v_p[3];
	float		det[3];
	int			i;

	i = 0;
	while (i < 3)
	{
		edge[i] = sub_vector2(triangle.coord[(i + 1) % 3], triangle.coord[i]);
		v_p[i] = sub_vector2(coord, triangle.coord[i]);
		det[i] = cross_vector2(edge[i], v_p[i]);
		i++;
	}
	if ((det[0] >= 0 && det[1] >= 0 && det[2] >= 0)
		|| (det[0] <= 0 && det[1] <= 0 && det[2] <= 0))
	{
		return (true);
	}
	return (false);
}

t_triangle	triangle_to_screen(t_triangle triangle)
{
	t_triangle	screen_triangle;
	int			i;

	i = 0;
	while (i < 3)
	{
		screen_triangle.coord[i] = world_to_screen(triangle.coord[i]);
		i++;
	}
	return (screen_triangle);
}

static void	sweep_triangle(t_render2d *buffer, t_render2d *render, int index)
{
	t_vector2	min;
	t_vector2	max;
	t_vector2	coord;
	t_triangle	triangle;

	triangle = triangle_to_screen(render->triangle[index]);
	get_min_max(&min, &max, triangle);
	coord = new_coord(min.x, min.y);
	while (coord.y < max.y)
	{
		coord.x = min.x;
		while (coord.x < max.x)
		{
			if (is_inside_triangle(coord, triangle))
			{
				if (coord.x > 0 && coord.y > 0 && coord.x < buffer->size.x && coord.y < buffer->size.y)
					copy_pixel(buffer, render, coord, (t_vector2){0, 0});
			}
			coord.x++;
		}
		coord.y++;
	}
}

void	render_2d(t_render2d *buffer)
{
	t_engine	*engine;
	t_vector2	coord;
	size_t		index;

	engine = get_engine();
	index = 0;
	while (index < OBJ_2D_MAX)
	{
		if (engine->object_2d[index] != NULL)
		{
			coord = world_to_screen(engine->object_2d[index]->coord);
			if (!culling_obj(coord.x, coord.y,
					engine->object_2d[index]->render.size.x,
					engine->object_2d[index]->render.size.y))
			{
				// printf("coord.x = %f, coord.y = %f\n", coord.x, coord.y);
				sweep_triangle(buffer, &engine->object_2d[index]->render, 0);
				sweep_triangle(buffer, &engine->object_2d[index]->render, 1);
			}
		}
		index++;
	}
}

// static void	draw_obj_to_frame(t_img *img, t_img *buffer, t_coord *obj_coord, float cam_angle)
// {
// 	t_coord	pixel_coord;
// 	t_coord pixel_offset;
// 	t_coord dst_coord;
// 	t_coord rotate_obj;

// 	pixel_coord.y = 0;
// 	while (pixel_coord.y < img->height)
// 	{
// 		pixel_coord.x = 0;
// 		pixel_offset.y = obj_coord->y - (img->height / 2);
// 		while (pixel_coord.x < img->width)
// 		{
// 			pixel_offset.x = obj_coord->x - (img->width / 2);
// 			rotate_obj.x = pixel_coord.x * cos(cam_angle) - pixel_coord.y * sin(cam_angle);
// 			rotate_obj.y = pixel_coord.x * sin(cam_angle) + pixel_coord.y * cos(cam_angle);
// 			dst_coord.x = pixel_offset.x + rotate_obj.x;
// 			dst_coord.y = pixel_offset.y - rotate_obj.y;
// 			if (dst_coord.x >= 0 && dst_coord.y >= 0 && dst_coord.x < buffer->width && dst_coord.y < buffer->height)
// 				copy_pixel(buffer, img, &dst_coord, &pixel_coord);
// 			pixel_coord.x++;
// 		}
// 		pixel_coord.y++;
// 	}
// }