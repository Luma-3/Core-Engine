/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:13:02 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/29 14:31:24 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_engine.h"
#include "render.h"

void	loop(void)
{
	t_engine	*engine;

	engine = get_engine();
	mlx_loop_hook(engine->mlx, renderer, NULL);
	mlx_loop(engine->mlx);
}
