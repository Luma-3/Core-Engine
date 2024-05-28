/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:03:12 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/28 13:32:45 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static bool	culling_obj(t_vector2 coord, t_vector2 size, int id_win)
{
	t_engine	*engine;

	engine = __get_engine();
	if (coord.x - (size.x / 2) > engine->win[id_win]->width
		|| coord.x + (size.x / 2) < 0)
	{
		return (true);
	}
	if (coord.y - (size.y / 2) > engine->win[id_win]->height
		|| coord.y + (size.y / 2) < 0)
	{
		return (true);
	}
	return (false);
}

static void	iter_2d(t_gobject **objs)
{
	int			i;
	t_vector2	coord;

	i = 0;
	while (i < MAX_2D_OBJ)
	{
		if (objs[i] != NULL
			&& objs[i]->render.texture != NULL
			&& objs[i]->render.draw != NULL)
		{
			coord = world_to_screen(
					objs[i]->trans.pos,
					objs[i]->render.id_win
					);
			if (culling_obj(coord,
					objs[i]->render.texture->size,
					objs[i]->render.id_win) == false)
			{
				objs[i]->render.draw(&(objs[i]->render));
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
		if (debug[i] != NULL
			&& debug[i]->draw_ray != NULL
			&& debug[i]->active == true)
			debug[i]->draw_ray(debug[i]);
		i++;
	}
}

void	__render_objets(t_engine *engine)
{
	iter_2d(engine->obj2d);
	iter_debug(engine->debug);
}
