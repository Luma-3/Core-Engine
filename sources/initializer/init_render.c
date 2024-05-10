/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:49:50 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/10 15:52:03 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "renderer.h"

static t_buffer	*init_buffer(size_t width, size_t height)
{
	t_buffer	*buffer;

	buffer = malloc(sizeof(t_buffer));
	if (!buffer)
	{
		logwarning(__FILE__, __LINE__, "init_buffer failed");
		return (NULL);
	}
	buffer->addr = mlx_get_data_addr(buffer->img, &buffer->bpp,
			&buffer->l_length, &buffer->endian);
	if (!buffer->addr)
	{
		logwarning(__FILE__, __LINE__, "mlx_get_data_addr() failed");
		free(buffer);
		return (NULL);
	}
	buffer->size = vector2(width, height);
	return (buffer);
}

static int	__draw_void(t_buffer *void_buf, int width, int height)
{
	t_vector2	coord;

	coord = vector2(0, 0);
	while (coord.y < height)
	{
		coord.x = 0;
		while (coord.x < width)
		{
			pixel_put(void_buf, coord, VOID_COLOR);
			coord.x++;
		}
		coord.y++;
	}
	return (SUCCESS);
}

static int	__init_d_buffer(t_mrender *render, size_t width, size_t height)
{
	render->b_back = malloc(sizeof(t_render2d));
	loginfo(__FILE__, __LINE__, "init_buffer backbuffer");
	if (!render->b_back)
	{
		logwarning(__FILE__, __LINE__, "init_buffer failed (backbuffer)");
		free(render->b_void);
		render = NULL;
		return (FAILURE);
	}
	render->b_front = malloc(sizeof(t_render2d));
	loginfo(__FILE__, __LINE__, "init_buffer frontbuffer");
	if (!render->b_front)
	{
		logwarning(__FILE__, __LINE__, "init_buffer failed (frontbuffer)");
		free(render->b_void);
		free(render->b_back);
		render = NULL;
		return (FAILURE);
	}
	render->b_back = init_buffer(width, height);
	render->b_front = init_buffer(width, height);
	return (SUCCESS);
}

int	__init_renderer(t_engine *engine)
{
	t_mrender	*renderer;

	renderer = get_renderer();
	loginfo(__FILE__, __LINE__, "init_renderer");
	renderer->b_void = malloc(sizeof(t_render2d));
	loginfo(__FILE__, __LINE__, "init_buffer renderer->voidbuffer");
	if (!renderer->b_void)
	{
		logwarning(__FILE__, __LINE__, "init_buffer failed (voidbuffer)");
		renderer = NULL;
		return (FAILURE);
	}
	renderer->b_void = init_buffer(engine->width, engine->height);
	__draw_void(renderer->b_void, engine->width, engine->height);
	mlx_put_image_to_window(engine->mlx, engine->win,
		renderer->b_void->img, 0, 0);
	if (__init_d_buffer(renderer, engine->width, engine->height) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
