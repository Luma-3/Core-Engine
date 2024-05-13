/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:29:25 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/13 14:13:46 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "renderer.h"

static bool	culling_obj(int x, int y, int width, int height)
{
	t_engine	*engine;

	engine = get_engine();
	if (x - (width / 2) > engine->width || x + (width / 2) < 0)
	{
		return (true);
	}
	if (y - (height / 2) > engine->height || y + (height / 2) < 0)
	{
		return (true);
	}
	return (false);
}

static void	iter_2d(t_render2d **render)
{
	int			i;
	t_vector3	coord;

	i = 0;
	while (i < MAX_2D_OBJ)
	{
		if (render[i] != NULL)
		{
			if (render[i]->draw != NULL)
			{
				coord = world_to_screen(vector3(render[i]->trans->pos.x, render[i]->trans->pos.y, 0));
				if (culling_obj(coord.x, coord.y,
					render[i]->size.x, render[i]->size.y) == false)
				{
					render[i]->draw(render[i]);
				}
			}
		}
		i++;
	}
}

static void	iter_debug(t_debug **debug)
{
	int	i;

	i = 0;
	while (i < MAX_DEBUG_OBJ)
	{
		if (debug[i] != NULL && debug[i]->draw_ray != NULL && debug[i]->active == true)
			debug[i]->draw_ray(debug[i]);
		i++;
	}
}

int	renderer(void)
{
	t_mrender	*renderer;

	renderer = get_renderer();
	ft_memcpy(renderer->b_back->addr, renderer->b_void->addr,
		get_engine()->width * get_engine()->height * 4);
	iter_2d(renderer->render2d);
	iter_debug(renderer->debug);
	swap_buffers(&renderer->b_front, &renderer->b_back);
	put_frame(renderer->b_front);
	return (SUCCESS);
}
