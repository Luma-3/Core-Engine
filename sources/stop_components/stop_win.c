/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:57:24 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/28 16:35:00 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	destroy_win(int id_win)
{
	t_engine	*engine;
	t_win		*win;

	engine = __get_engine();
	win = engine->win[id_win];
	mlx_clear_window(engine->mlx, win->win_ptr);
	if (win->title)
		free(win->title);
	__destroy_renderer(&win->renderer);
	mlx_destroy_window(engine->mlx, win->win_ptr);
	free(win);
}
