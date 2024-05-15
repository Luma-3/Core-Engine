/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:13:02 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/15 16:52:04 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "renderer.h"

int	loop_function(void *param)
{
	t_engine	*engine;

	engine = get_engine();

	renderer(param);
	return (0);
}

void	loop(int (*f)(void *), void *param)
{
	t_engine	*engine;

	engine = get_engine();
	engine->loop_f = f;
	mlx_loop_hook(engine->mlx, &loop_function, param);
	mlx_loop(engine->mlx);
}
