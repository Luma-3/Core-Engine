/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:13:34 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/10 15:39:36 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "core.h"

static int	__get_addr(t_render2d *render)
{
	render->addr = mlx_get_data_addr(render->img, &render->bpp,
			&render->l_length, &render->endian);
	if (!render->addr)
	{
		logwarning(__FILE__, __LINE__, "mlx_get_data_addr() failed");
		return (FAILURE);
	}
	return (SUCCESS);
}

int	init_xmp_render2d(t_game_object *obj, const char *file)
{
	t_render2d	render;
	int			width;
	int			height;

	render.img = mlx_xpm_file_to_image(get_engine()->mlx, (char *)file,
			&height, &width);
	if (!render.img)
	{
		logerror(__FILE__, __LINE__, "mlx_xpm_file_to_image() failed");
		return (FAILURE);
	}
	if (__get_addr(&render) == FAILURE)
		return (FAILURE);
	render.size = vector2(width, height);
	render.trans = &obj->trans;
	obj->render = render;
	return (SUCCESS);
}

int	init_render2d(t_game_object *obj, size_t width, size_t height)
{
	t_render2d	render;

	render.img = mlx_new_image(get_engine()->mlx, width, height);
	if (!render.img)
	{
		logerror(__FILE__, __LINE__, "mlx_new_image() failed");
		return (FAILURE);
	}
	if (__get_addr(&render) == FAILURE)
		return (FAILURE);
	render.size = vector2(width, height);
	render.trans = &obj->trans;
	obj->render = render;
	return (SUCCESS);
}
