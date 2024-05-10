/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:16:29 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/10 15:57:10 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "renderer.h"

void	swap_buffers(t_buffer **front, t_buffer **back)
{
	t_buffer	*tmp;

	tmp = *front;
	*front = *back;
	*back = tmp;
}

void	put_frame(t_buffer *frame)
{
	t_engine	*engine;

	engine = get_engine();
	mlx_put_image_to_window(engine->mlx, engine->win, frame->img, 0, 0);
}
