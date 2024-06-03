/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:43:18 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/03 20:00:30 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "X11/Xlib.h"
#include "core.h"

int	init_engine(void)
{
	t_engine	*engine;

	__init_logger();
	engine = __get_engine();
	ft_bzero(engine, sizeof(t_engine));
	engine->mlx = mlx_init();
	logdebug(__FILE__, __LINE__, "mlx_init() called");
	if (!engine->mlx)
	{
		stop_engine();
		logerror(__FILE__, __LINE__, "mlx_init() failed");
		return (FAILURE);
	}
	return (SUCCESS);
}
