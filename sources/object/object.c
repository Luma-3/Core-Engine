/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:18:18 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/07 16:18:21 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "core_engine.h"

static void	change_coord(t_object2d *obj, t_vector2 coord)
{
	obj->coord = new_coord(coord.x, coord.y);
	if (obj->render.img)
		__cal_triangle(&obj->render, obj->coord, obj->render.size);
}

t_object2d	*new_obj2d(char *name, unsigned int id)
{
	t_object2d	*object;
	t_engine	*engine;

	engine = get_engine();
	object = (t_object2d *)malloc(sizeof(t_object2d));
	if (!object)
	{
		logerror(__FILE__, __LINE__, "malloc() failed");
		return (NULL);
	}
	ft_bzero(object, sizeof(t_object2d));
	object->coord = new_coord(0, 0);
	object->name = strdup(name);
	if (!object->name)
	{
		logerror(__FILE__, __LINE__, "strdup() failed");
		return (NULL);
	}
	object->id = id;
	engine->object_2d[id] = object;
	object->change_coord = change_coord;
	return (object);
}
