/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:10:05 by antgabri          #+#    #+#             */
/*   Updated: 2024/05/15 11:33:39 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "core.h"

static void	__draw_line(t_vector2 start, t_vector2 end, t_buffer *buffer,
	int color)
{
	t_vector2	delta;
	int			steps;
	t_vector2	increment;
	t_vector2	coord;
	int			i;

	delta = sub_vector2(end, start);
	if (abs((int)delta.x) > abs((int)delta.y))
		steps = abs((int)delta.x);
	else
		steps = abs((int)delta.y);
	increment.x = delta.x / (float)steps;
	increment.y = delta.y / (float)steps;
	coord.x = start.x;
	coord.y = start.y;
	i = 0;
	while (i <= steps)
	{
		if (coord.x >= 0 && coord.x < buffer->size.x && coord.y >= 0
			&& coord.y < buffer->size.y)
			pixel_put(buffer, (t_vector2){coord.x, coord.y}, color);
		coord.x += increment.x;
		coord.y += increment.y;
		i++;
	}
}

void	draw_ray(void *obj)
{
	t_engine	*engine;
	t_debug		*debug;

	engine = get_engine();
	debug = (t_debug *)obj;
	__draw_line(debug->start, debug->end, engine->win[debug->id_win].renderer->b_back, debug->color);
}
