/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:17:11 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/28 12:33:51 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_engine.h"

int	__close_mlx(t_engine *engine)
{
	if (engine->win && engine->mlx)
	{
		mlx_destroy_window(engine->mlx, engine->win);
		logdebug(__FILE__, __LINE__, "mlx_destroy_window() called");
	}
	if (engine->mlx)
	{
		mlx_destroy_display(engine->mlx);
		logdebug(__FILE__, __LINE__, "mlx_destroy_display() called");
	}
	if (engine->mlx)
	{
		free(engine->mlx);
		logdebug(__FILE__, __LINE__, "Freeing mlx");
	}
	return (SUCCESS);
}

int	__clear_engine(t_engine *engine)
{
	if (engine->title)
	{
		free(engine->title);
		logdebug(__FILE__, __LINE__, "Freeing engine->title");
	}
	engine = NULL;
	logdebug(__FILE__, __LINE__, "Freeing engine");
	return (SUCCESS);
}

int	stop_engine(void)
{
	t_engine	*engine;

	engine = get_engine();
	__close_mlx(engine);
	__clear_engine(engine);
	close_logfile();
	exit(SUCCESS);
}
