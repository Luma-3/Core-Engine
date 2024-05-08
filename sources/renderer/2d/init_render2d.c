/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:13:34 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/08 16:27:46 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "core_engine.h"

// void	__cal_triangle(t_render2d *render, t_vector2 coord, t_vector2 size, float angle)
// {
// 	float cos_angle = cos(angle);
// 	float sin_angle = sin(angle);

// 	render->triangle[0].coord[0]
// 		= new_coord(coord.x - (size.x / 2) * cos_angle + (size.y / 2) * sin_angle, coord.y - (size.y / 2) * cos_angle - (size.x / 2) * sin_angle);
// 	render->triangle[0].coord[1]
// 		= new_coord(coord.x + (size.x / 2) * cos_angle + (size.y / 2) * sin_angle, coord.y - (size.y / 2) * cos_angle + (size.x / 2) * sin_angle);
// 	render->triangle[0].coord[2]
// 		= new_coord(coord.x - (size.x / 2) * cos_angle - (size.y / 2) * sin_angle, coord.y + (size.y / 2) * cos_angle - (size.x / 2) * sin_angle);
// 	render->triangle[1].coord[0]
// 		= new_coord(coord.x + (size.x / 2) * cos_angle - (size.y / 2) * sin_angle, coord.y + (size.y / 2) * cos_angle + (size.x / 2) * sin_angle);
// 	render->triangle[1].coord[1]
// 		= new_coord(coord.x - (size.x / 2) * cos_angle - (size.y / 2) * sin_angle, coord.y + (size.y / 2) * cos_angle - (size.x / 2) * sin_angle);
// 	render->triangle[1].coord[2]
// 		= new_coord(coord.x + (size.x / 2) * cos_angle + (size.y / 2) * sin_angle, coord.y - (size.y / 2) * cos_angle + (size.x / 2) * sin_angle);
// }

static void	__get_addr(t_render2d *render)
{
	render->addr = mlx_get_data_addr(render->img, &render->bpp,
			&render->l_length, &render->endian);
	if (!render->addr)
	{
		logwarning(__FILE__, __LINE__, "mlx_get_data_addr() failed");
	}
	// __cal_triangle(render, new_coord(0, 0), render->size, 0);
}

t_render2d	init_xmp_render2d(const char *file)
{
	t_render2d	render;
	int			width;
	int			height;

	render.img = mlx_xpm_file_to_image(get_engine()->mlx, (char *)file,
			&height, &width);
	if (!render.img)
	{
		logerror(__FILE__, __LINE__, "mlx_xpm_file_to_image() failed");
		return ((t_render2d){0});
	}
	__get_addr(&render);
	render.size = new_coord(width, height);
	// printf("render.size.x = %f, render.size.y = %f\n", render.size.x, render.size.y);
	return (render);
}

t_render2d	init_render2d(size_t width, size_t height)
{
	t_render2d	render;

	render.img = mlx_new_image(get_engine()->mlx, width, height);
	if (!render.img)
	{
		logerror(__FILE__, __LINE__, "mlx_new_image() failed");
		return ((t_render2d){0});
	}
	__get_addr(&render);
	render.size = new_coord(width, height);
	return (render);
}
