/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:09:47 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/15 11:43:40 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "logging.h"

int	init_window(t_vector2 win_size, char *title)
{
	t_engine	*engine;

	engine = get_engine();
	if (engine->nb_win >= MAX_WIN)
	{
		logerror(__FILE__, __LINE__, "Too many windows");
		return (FAILURE);
	}
	engine->win[engine->nb_win].win_ptr = mlx_new_window(engine->mlx,
			win_size.x, win_size.y, title);
	if (!engine->win[engine->nb_win].win_ptr)
	{
		logerror(__FILE__, __LINE__, "Failed to create window");
		return (FAILURE);
	}
	engine->win[engine->nb_win].width = win_size.x;
	engine->win[engine->nb_win].height = win_size.y;
	engine->win[engine->nb_win].title = title;
	if (__init_renderer(engine->mlx,
			&(engine->win[engine->nb_win]), win_size) == FAILURE)
		return (FAILURE);
	engine->nb_win++;
	return (SUCCESS);
}
