/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:50:02 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/27 11:53:18 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	destroy_renderer(t_mrender *renderer)
{
	t_engine	*engine;

	engine = get_engine();
	mlx_destroy_image(engine->mlx, renderer->b_back->img);
	free(renderer->b_back);
	mlx_destroy_image(engine->mlx, renderer->b_front->img);
	free(renderer->b_front);
	mlx_destroy_image(engine->mlx, renderer->b_void->img);
	free(renderer->b_void);
}
