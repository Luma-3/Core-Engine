/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:29:25 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/17 18:43:13 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "renderer.h"

static bool	culling_obj(t_vector2 coord, t_vector2 size, int id_win)
{
	t_engine	*engine;

	engine = get_engine();
	if (coord.x - (size.x / 2) > engine->win[id_win]->width || coord.x + (size.x / 2) < 0)
	{
		return (true);
	}
	if (coord.y - (size.y / 2) > engine->win[id_win]->height || coord.y + (size.y / 2) < 0)
	{
		return (true);
	}
	return (false);
}

static void	iter_2d(t_game_object **objs)
{
	int			i;
	t_vector2	coord;

	i = 0;
	while (i < MAX_2D_OBJ)
	{
		if (objs[i] != NULL && objs[i]->render.texture != NULL)
		{
			if (objs[i]->render.draw != NULL)
			{
				coord = world_to_screen(objs[i]->trans.pos,
						objs[i]->render.id_win);
				if (culling_obj(coord, objs[i]->render.texture->size, objs[i]->render.id_win) == false)
				{
					objs[i]->render.draw(&(objs[i]->render));
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

int	renderer(void *param)
{
	t_engine	*engine;
	int 		i;

	i = 0;
	engine = get_engine();
	while (i < engine->nb_win)
	{
		ft_memcpy(engine->win[i]->renderer.b_back->addr, engine->win[i]->renderer.b_void->addr,
			engine->win[i]->width * engine->win[i]->height * 4);
		i++;
	}
	iter_2d(engine->obj2d);
	if (engine->loop_f)
		engine->loop_f(param);
	iter_debug(engine->debug);
	i = 0;
	while (i < engine->nb_win)
	{
		swap_buffers(&engine->win[i]->renderer.b_front, &engine->win[i]->renderer.b_back);
		put_frame(engine->win[i]->renderer.b_front, engine->win[i]);
		i++;
	}
	return (SUCCESS);
}
