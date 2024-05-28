/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:17:08 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/28 13:32:45 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "renderer.h"
#include "core.h"

t_debug	*new_debug(t_vector2 start, t_vector2 end, int id)
{
	t_debug		*debug;
	t_engine	*engine;

	engine = __get_engine();
	debug = malloc(sizeof(t_debug));
	if (!debug)
		return (NULL);
	ft_bzero(debug, sizeof(t_debug));
	debug->start = start;
	debug->end = end;
	debug->draw_ray = draw_ray;
	engine->debug[id] = debug;
	return (debug);
}
