/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:09:47 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/15 13:22:04 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "logging.h"

int	init_window(t_vector2 win_size, char *title)
{
	t_engine	*engine;
	t_win		*win;

	win = malloc(sizeof(t_win));
	if (!win)
	{
		logerror(__FILE__, __LINE__, "Failed to allocate memory for window");
		return (FAILURE);
	}
	engine = get_engine();
	if (engine->nb_win >= MAX_WIN)
	{
		logerror(__FILE__, __LINE__, "Too many windows");
		return (FAILURE);
	}
	win->win_ptr = mlx_new_window(engine->mlx,
			win_size.x, win_size.y, title);
	if (!win->win_ptr)
	{
		logerror(__FILE__, __LINE__, "Failed to create window");
		return (FAILURE);
	}
	win->width = win_size.x;
	win->height = win_size.y;
	win->title = title;
	if (__init_renderer(engine->mlx, win, win_size) == FAILURE)
		return (FAILURE);
	engine->win[engine->nb_win] = win;
	engine->nb_win++;
	return (SUCCESS);
}

