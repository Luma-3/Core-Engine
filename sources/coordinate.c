/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:30:06 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/10 12:26:42 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "logic.h"
#include "core_engine.h"

t_vector3	vector3(float x, float y, float z)
{
	t_vector3	coord;

	coord.x = x;
	coord.y = y;
	coord.z = z;
	return (coord);
}

t_vector3	world_to_screen(t_vector3 world)
{
	t_engine	*engine;
	t_vector3	screen;
	t_vector3	offset_cam;

	engine = get_engine();
	screen = vector3(0, 0, world.z);
	offset_cam.x = world.x + engine->camera->coord.x;
	offset_cam.y = world.y + engine->camera->coord.y;
	screen.x = offset_cam.x * cos(engine->camera->angle)
		- offset_cam.y * sin(engine->camera->angle);
	screen.y = offset_cam.x * sin(engine->camera->angle)
		+ offset_cam.y * cos(engine->camera->angle);
	screen.x = screen.x + (engine->width / 2);
	screen.y = (engine->height / 2) - screen.y;
	return (screen);
}
