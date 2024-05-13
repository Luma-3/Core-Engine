/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:18:18 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/13 14:15:00 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "core.h"
#include "renderer.h"

t_game_object	*new_object(unsigned int id)
{
	t_game_object	*object;
	t_engine		*engine;

	engine = get_engine();
	object = (t_game_object *)malloc(sizeof(t_game_object));
	if (!object)
	{
		logerror(__FILE__, __LINE__, "malloc() failed");
		return (NULL);
	}
	ft_bzero(object, sizeof(t_game_object));
	object->trans.scale = vector2(1, 1);
	object->id = id;
	engine->obj2d[id] = object;
	engine->obj2d_count++;
	return (object);
}
