/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:30:06 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/28 13:32:45 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

t_vector2	world_to_screen(t_vector2 world, int id_win)
{
	t_engine	*engine;
	t_vector2	screen;
	t_vector2	comput_offset;

	engine = __get_engine();
	comput_offset = add_vector2(world, engine->win[id_win]->offset);
	screen.x = comput_offset.x + (engine->win[id_win]->width / 2);
	screen.y = (engine->win[id_win]->height / 2) - comput_offset.y;
	return (screen);
}
