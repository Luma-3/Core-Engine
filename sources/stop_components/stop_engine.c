/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:17:11 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/28 18:14:16 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static int	__close_mlx(t_engine *engine)
{
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

static int	__clear_engine(t_engine *engine)
{
	engine = NULL;
	(void)engine;
	logdebug(__FILE__, __LINE__, "Freeing engine");
	return (SUCCESS);
}

int	stop_engine(void)
{
	t_engine	*engine;

	engine = __get_engine();
	while (engine->nb_win > 0)
	{
		engine->nb_win--;
		if (engine->win[engine->nb_win])
		{
			destroy_win(engine->nb_win);
		}
	}
	__close_mlx(engine);
	__clear_engine(engine);
	__close_logfile();
	exit(SUCCESS);
}
