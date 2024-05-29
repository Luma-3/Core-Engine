/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:49:50 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/29 11:51:24 by antgabri         ###   ########.fr       */
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
	buffer->img = mlx_new_image(__get_engine()->mlx, width, height);
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

static int	draw_void(t_win *win, int width, int height)
{
	t_vector2	coord;

	coord = vector2(0, 0);
	while (coord.y < height)
	{
		coord.x = 0;
		while (coord.x < width)
		{
			pixel_put(win, coord, VOID_COLOR);
			coord.x++;
		}
		coord.y++;
	}
	return (SUCCESS);
}

static int	init_d_buffer(t_mrender *render, size_t width, size_t height)
{
	render->b_back = init_buffer(width, height);
	if (!render->b_back)
		return (FAILURE);
	render->b_front = init_buffer(width, height);
	if (!render->b_front)
	{
		free(render->b_back);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	__init_renderer(void *mlx_ptr, t_win *win, t_vector2 win_size)
{
	win->renderer.b_void = init_buffer(win_size.x, win_size.y);
	if (!win->renderer.b_void)
		return (FAILURE);
	draw_void(win, win_size.x, win_size.y);
	mlx_put_image_to_window(mlx_ptr, win->win_ptr,
		win->renderer.b_void->img, 0, 0);
	if (init_d_buffer(&(win->renderer), win_size.x, win_size.y) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
