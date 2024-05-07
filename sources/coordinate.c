/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:30:06 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/07 17:41:37 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_engine.h"

t_vector2	new_coord(float x, float y)
{
	t_vector2	coord;

	coord.x = x;
	coord.y = y;
	return (coord);
}

t_vector2	screen_to_world(t_vector2 screen)
{
	t_engine	*engine;
	t_vector2	world;

	engine = get_engine();
	world = new_coord(0, 0);
	world.x = screen.x * engine->width;
	world.y = screen.y * engine->height;
	return (world);
}

t_vector2	world_to_screen(t_vector2 world)
{
	t_engine	*engine;
	t_vector2	screen;
	t_vector2	offset_cam;

	engine = get_engine();
	screen = new_coord(0, 0);
	offset_cam.x = world.x + engine->camera->coord.x;
	offset_cam.y = world.y + engine->camera->coord.y;
	// printf("camera x: %f, y: %f\n", engine->camera->coord.x, engine->camera->coord.y);

	screen.x = offset_cam.x * cos(engine->camera->angle) - offset_cam.y * sin(engine->camera->angle);
	screen.y = offset_cam.x * sin(engine->camera->angle) + offset_cam.y * cos(engine->camera->angle);

	screen.x = screen.x + (engine->width / 2);
	screen.y = (engine->height / 2) - screen.y;
	// printf("camera x: %f, y: %f\n", engine->camera->coord->x, engine->camera->coord->y);
	return (screen);
}

void	print_coord(t_vector2 *coord)
{
	printf("x: %f, y: %f\n", coord->x, coord->y);
}
