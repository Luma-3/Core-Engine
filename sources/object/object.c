/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:18:18 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/10 12:30:40 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "core_engine.h"

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
	object->coord = vector3(0, 0);
	object->name = strdup(name);
	if (!object->name)
	{
		logerror(__FILE__, __LINE__, "strdup() failed");
		return (NULL);
	}
	object->id = id;
	object->scale = 1;
	engine->object_2d[id] = object;
	return (object);
}
