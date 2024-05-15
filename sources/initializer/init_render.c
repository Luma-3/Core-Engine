/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:49:50 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/15 10:49:24 by jbrousse         ###   ########.fr       */
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
	buffer->img = mlx_new_image(get_engine()->mlx, width, height);
	if (!buffer->img)
	{
		logwarning(__FILE__, __LINE__, "mlx_new_image() failed");
		free(buffer);
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
	render->b_back = init_buffer(width, height);
	render->b_front = init_buffer(width, height);
	return (SUCCESS);
}

int	__init_renderer(void *mlx_ptr, t_win *win, t_vector2 win_size)
{
	win->renderer->b_void = malloc(sizeof(t_buffer));
	loginfo(__FILE__, __LINE__, "init_buffer renderer->voidbuffer");
	if (!win->renderer->b_void)
	{
		logwarning(__FILE__, __LINE__, "init_buffer failed (voidbuffer)");
		win->renderer = NULL;
		return (FAILURE);
	}
	win->renderer->b_void = init_buffer(win_size.x, win_size.y);
	__draw_void(win->renderer->b_void, win_size.x, win_size.y);
	mlx_put_image_to_window(mlx_ptr, win->win_ptr,
		win->renderer->b_void->img, 0, 0);
	if (__init_d_buffer(win->renderer, win_size.x, win_size.y) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
