/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:13:02 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/28 14:35:07 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "renderer.h"

void	add_loop_update(int (*f)(void *), void *param)
{
	t_engine	*engine;

	engine = __get_engine();
	engine->update_param = param;
	engine->update = f;
}

void	add_loop_render(int (*f)(void *), void *param)
{
	t_engine	*engine;

	engine = __get_engine();
	engine->render_param = param;
	engine->render_f = f;
}

int	__loop_function(void *engine_ptr)
{
	t_engine	*engine;

	engine = (t_engine *)engine_ptr;
	if (engine->update != NULL)
		engine->update(engine->update_param);
	__renderer(engine->render_param);
	return (0);
}

void	loop(void)
{
	t_engine	*engine;

	engine = __get_engine();
	mlx_loop_hook(engine->mlx, &__loop_function, engine);
	mlx_loop(engine->mlx);
}
