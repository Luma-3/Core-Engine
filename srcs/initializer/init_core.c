/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:43:18 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/28 01:12:25 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_engine.h"

int	init_core(void)
{
	t_engine	*engine;

	init_logger();
	engine = get_engine();
	if (read_config(engine) == FAILURE)
	{
		logerror(__FILE__, __LINE__, "read_config() failed");
		return (FAILURE);
	}
	engine->mlx = mlx_init();
	logdebug(__FILE__, __LINE__, "mlx_init() called");
	if (!engine->mlx)
	{
		logerror(__FILE__, __LINE__, "mlx_init() failed");
		return (FAILURE);
	}
	engine->win = mlx_new_window(engine->mlx, engine->width, engine->height,
			engine->title);
	logdebug(__FILE__, __LINE__, "mlx_new_window() called");
	if (!engine->win)
	{
		logerror(__FILE__, __LINE__, "mlx_new_window() failed");
		return (FAILURE);
	}
	return (SUCCESS);
}
