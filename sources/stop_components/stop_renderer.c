/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:50:02 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/28 13:32:45 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	__destroy_renderer(t_mrender *renderer)
{
	t_engine	*engine;

	engine = __get_engine();
	mlx_destroy_image(engine->mlx, renderer->b_back->img);
	free(renderer->b_back);
	mlx_destroy_image(engine->mlx, renderer->b_front->img);
	free(renderer->b_front);
	mlx_destroy_image(engine->mlx, renderer->b_void->img);
	free(renderer->b_void);
}
