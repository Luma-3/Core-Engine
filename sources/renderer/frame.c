/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:16:29 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/28 13:32:45 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "renderer.h"

void	__swap_buffers(t_buffer **front, t_buffer **back)
{
	t_buffer	*tmp;

	tmp = *front;
	*front = *back;
	*back = tmp;
}

void	__put_frame(t_buffer *frame, void *win)
{
	t_engine	*engine;
	t_win		*window;

	window = (t_win *)win;
	engine = __get_engine();
	mlx_put_image_to_window(engine->mlx, window->win_ptr, frame->img, 0, 0);
}
