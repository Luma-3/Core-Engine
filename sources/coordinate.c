/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:30:06 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/15 13:22:49 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "logic.h"
#include "core.h"

t_vector2	world_to_screen(t_vector2 world, int id_win)
{
	t_engine	*engine;
	t_vector2	screen;
	t_vector2	comput_offset;

	engine = get_engine();
	comput_offset = add_vector2(world, engine->win[id_win]->offset);
	screen.x = comput_offset.x + (engine->win[id_win]->width / 2);
	screen.y = (engine->win[id_win]->height / 2) - comput_offset.y;
	return (screen);
}
