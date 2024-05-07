/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:16:29 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/07 13:40:43 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_engine.h"
#include "render.h"

void	swap_buffers(t_render2d **front, t_render2d **back)
{
	t_render2d	*tmp;

	tmp = *front;
	*front = *back;
	*back = tmp;
}

int	double_buffering(t_render2d **front, t_render2d **back,
		t_render2d *voidbuffer)
{
	t_engine	*engine;

	engine = get_engine();
	ft_memcpy((*back)->addr, voidbuffer->addr,
		engine->width * engine->height * 4);
	render_2d(*back);
	swap_buffers(front, back);
	put_frame(*front);
	return (SUCCESS);
}

void	put_frame(t_render2d *frame)
{
	t_engine	*engine;

	engine = get_engine();
	mlx_put_image_to_window(engine->mlx, engine->win, frame->img, 0, 0);
}
