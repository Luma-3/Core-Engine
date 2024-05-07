/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:49:50 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/07 16:06:44 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_engine.h"

static int	__draw_void(t_render2d *void_buf, int width, int height)
{
	t_vector2	coord;

	coord = new_coord(0, 0);
	while (coord.y < height)
	{
		coord.x = 0;
		while (coord.x < width)
		{
			pixel_put(void_buf, &coord, VOID_COLOR);
			coord.x++;
		}
		coord.y++;
	}
	return (SUCCESS);
}

static int	__init_double_buffering(t_engine *engine)
{
	*(engine->renderer->drawbuffer) = init_render2d(engine->width, engine->height);
	logdebug(__FILE__, __LINE__, "init_buffer renderer->drawbuffer");
	if (!engine->renderer->drawbuffer)
	{
		logerror(__FILE__, __LINE__, "init_buffer failed \
(renderer->drawbuffer)");
		free(engine->renderer->voidbuffer);
		free(engine->renderer);
		return (FAILURE);
	}
	*(engine->renderer->vbuffer) = init_render2d(engine->width, engine->height);
	logdebug(__FILE__, __LINE__, "init_buffer renderer->vbuffer");
	if (!engine->renderer->vbuffer)
	{
		logerror(__FILE__, __LINE__, "init_buffer failed (renderer->vbuffer)");
		free(engine->renderer->drawbuffer);
		free(engine->renderer->voidbuffer);
		free(engine->renderer);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	__init_renderer(t_engine *engine)
{
	engine->renderer = malloc(sizeof(t_buffers));
	if (!engine->renderer)
	{
		logerror(__FILE__, __LINE__, "malloc() failed");
		return (FAILURE);
	}
	*(engine->renderer->voidbuffer) = init_render2d(engine->width, engine->height);
	logdebug(__FILE__, __LINE__, "init_buffer renderer->voidbuffer");
	if (!engine->renderer->voidbuffer)
	{
		logerror(__FILE__, __LINE__, "init_buffer failed \
(renderer->voidbuffer)");
		free(engine->renderer);
		return (FAILURE);
	}
	__draw_void(engine->renderer->voidbuffer, engine->width, engine->height);
	mlx_put_image_to_window(engine->mlx, engine->win,
		engine->renderer->voidbuffer->img, 0, 0);
	if (__init_double_buffering(engine) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
