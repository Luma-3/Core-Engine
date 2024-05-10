/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:19:27 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/10 15:53:36 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int	key_hook(int (*f)(), void *param)
{
	t_engine	*engine;

	engine = get_engine();
	return (mlx_key_hook(engine->win, f, param));
}

int	mouse_hook(int (*f)(), void *param)
{
	t_engine	*engine;

	engine = get_engine();
	return (mlx_mouse_hook(engine->win, f, param));
}

int	loop_hook(int (*f)(), void *param)
{
	t_engine	*engine;

	engine = get_engine();
	return (mlx_loop_hook(engine->mlx, f, param));
}

int	expose_hook(int (*f)(), void *param)
{
	t_engine	*engine;

	engine = get_engine();
	return (mlx_expose_hook(engine->win, f, param));
}

int	event_hook(int (*f)(), int envent, int mask, void *param)
{
	t_engine	*engine;

	engine = get_engine();
	return (mlx_hook(engine->win, envent, mask, f, param));
}
