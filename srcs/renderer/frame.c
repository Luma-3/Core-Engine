/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:16:29 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/29 15:54:42 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_engine.h"
#include "render.h"

void	put_frame(t_img *frame)
{
	t_engine *engine;

	engine = get_engine();
	mlx_put_image_to_window(engine->mlx, engine->win, frame->img, 0, 0);
}