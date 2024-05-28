/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:09:47 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/28 15:55:00 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "logging.h"

static t_win	*base_win(const char *title)
{
	t_win	*win;

	win = ft_calloc(1, sizeof(t_win));
	if (!win)
	{
		logerror(__FILE__, __LINE__, "Failed to allocate memory for window");
		return (NULL);
	}
	win->title = ft_strdup(title);
	if (win->title == NULL)
	{
		logerror(__FILE__, __LINE__,
			"Failed to allocate memory for window title");
		free(win);
		return (NULL);
	}
	return (win);
}

static int	mlx_render_init(t_win *win, t_engine *engine, t_vector2 size)
{
	win->win_ptr = mlx_new_window(engine->mlx,
			size.x, size.y, win->title);
	if (!win->win_ptr)
	{
		logerror(__FILE__, __LINE__, "Failed to create window");
		free(win->title);
		free(win);
		return (FAILURE);
	}
	if (__init_renderer(engine->mlx, win, size) == FAILURE)
	{
		logerror(__FILE__, __LINE__, "Failed to initialize renderer");
		mlx_destroy_window(engine->mlx, win->win_ptr);
		free(win->title);
		free(win);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	init_window(t_vector2 win_size, const char *title)
{
	t_engine	*engine;
	t_win		*win;

	engine = __get_engine();
	if (engine->nb_win >= MAX_WIN)
	{
		logerror(__FILE__, __LINE__, "Too many windows");
		return (FAILURE);
	}
	win = base_win(title);
	if (win == NULL)
		return (FAILURE);
	if (mlx_render_init(win, engine, win_size) == FAILURE)
		return (FAILURE);
	win->width = win_size.x;
	win->height = win_size.y;
	engine->win[engine->nb_win] = win;
	engine->nb_win++;
	return (SUCCESS);
}
