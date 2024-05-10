/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:17:08 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/10 17:03:49 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "renderer.h"

t_debug	*new_debug(t_vector2 start, t_vector2 end, int id)
{
	t_debug		*debug;
	t_mrender	*renderer;

	renderer = get_renderer();
	debug = malloc(sizeof(t_debug));
	if (!debug)
		return (NULL);
	ft_bzero(debug, sizeof(t_debug));
	debug->start = start;
	debug->end = end;
	debug->draw_ray = draw_ray;
	renderer->debug[id] = debug;
	return (debug);
}
