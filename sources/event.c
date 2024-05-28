/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:19:27 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/28 13:32:45 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int	key_hook(int (*f)(), void *param)
{
	t_engine	*engine;

	engine = __get_engine();
	return (mlx_key_hook(engine->win, f, param));
}

int	mouse_hook(int (*f)(), void *param)
{
	t_engine	*engine;

	engine = __get_engine();
	return (mlx_mouse_hook(engine->win, f, param));
}

int	expose_hook(int (*f)(), void *param)
{
	t_engine	*engine;

	engine = __get_engine();
	return (mlx_expose_hook(engine->win, f, param));
}

int	event_hook(int (*f)(), int maskage[2], void *param, int id_win)
{
	t_engine	*engine;

	engine = __get_engine();
	return (mlx_hook(engine->win[id_win]->win_ptr,
			maskage[0], maskage[1], f, param));
}
