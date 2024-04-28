/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:30:06 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/28 14:36:04 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_engine.h"

t_coord	*new_coord(float x, float y)
{
	t_coord	*coord;

	coord = malloc(sizeof(t_coord));
	if (!coord)
	{
		logerror(__FILE__, __LINE__, "malloc() failed");
		return (NULL);
	}
	coord->x = x;
	coord->y = y;
	return (coord);
}

void	free_coord(t_coord *coord)
{
	if (coord)
		free(coord);
}

t_coord	*screen_to_world(t_coord *screen)
{
	t_engine	*engine;
	t_coord		*world;

	engine = get_engine();
	world = new_coord(0, 0);
	if (!world)
		return (NULL);
	world->x = screen->x * engine->width;
	world->y = screen->y * engine->height;
	return (world);
}

t_coord	*world_to_screen(t_coord *world)
{
	t_engine	*engine;
	t_coord		*screen;

	engine = get_engine();
	screen = new_coord(0, 0);
	if (!screen)
		return (NULL);
	screen->x = world->x / engine->width;
	screen->y = world->y / engine->height;
	return (screen);
}

void	print_coord(t_coord *coord)
{
	printf("x: %f, y: %f\n", coord->x, coord->y);
}
