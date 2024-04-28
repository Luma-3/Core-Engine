/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:49:50 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/28 15:31:36 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_engine.h"

int	__draw_void(t_engine *engine)
{
	t_coord	*coord;

	coord = new_coord(0, 0);
	if (!coord)
		return (FAILURE);
	while (coord->y < engine->height)
	{
		coord->x = 0;
		while (coord->x < engine->width)
		{
			pixel_put(engine->renderer->voidbuffer, coord, VOID_COLOR);
			coord->x++;
		}
		coord->y++;
	}
	free_coord(coord);
	return (SUCCESS);
}

int	init_renderer(void)
{
	t_engine	*engine;

	engine = get_engine();
	engine->renderer = malloc(sizeof(t_renderer));
	if (!engine->renderer)
	{
		logerror(__FILE__, __LINE__, "malloc() failed");
		return (FAILURE);
	}
	engine->renderer->voidbuffer = init_img(engine->width, engine->height);
	if (!engine->renderer->voidbuffer)
	{
		free(engine->renderer);
		return (FAILURE);
	}
	__draw_void(engine);
	mlx_put_image_to_window(engine->mlx, engine->win,
		engine->renderer->voidbuffer->img, 0, 0);
	return (SUCCESS);
}
