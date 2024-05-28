/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:18:18 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/28 13:32:45 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "core.h"
#include "renderer.h"

t_gobject	*new_object(unsigned int id, t_texture *texture,
	unsigned int win_id)
{
	t_gobject	*object;
	t_engine	*engine;

	engine = __get_engine();
	if (texture == NULL)
	{
		logwarning(__FILE__, __LINE__,
			"the *texture of an object must not be NULL");
		return (NULL);
	}
	object = (t_gobject *)malloc(sizeof(t_gobject));
	if (!object)
	{
		logerror(__FILE__, __LINE__, "malloc() failed");
		return (NULL);
	}
	ft_bzero(object, sizeof(t_gobject));
	object->trans.scale = vector2(1, 1);
	object->id = id;
	engine->obj2d[id] = object;
	engine->obj2d_count++;
	object->render.texture = texture;
	object->render.id_win = win_id;
	object->render.trans = &object->trans;
	return (object);
}

void	destroy_object(t_gobject *object, int do_destroy_texture)
{
	t_engine	*engine;

	if (object == NULL)
	{
		logwarning(__FILE__, __LINE__, "object is NULL");
		return ;
	}
	engine = __get_engine();
	engine->obj2d[object->id] = NULL;
	engine->obj2d_count--;
	if (do_destroy_texture == 1)
		destroy_texture(object->render.texture);
	free(object);
}
