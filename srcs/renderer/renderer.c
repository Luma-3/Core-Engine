/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:29:25 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/29 15:54:33 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_engine.h"
#include "render.h"

void	swap_buffers(t_img **front, t_img **back)
{
	t_img *tmp;

	tmp = *front;
	*front = *back;
	*back = tmp;
}

int double_buffering(t_img **front, t_img **back, t_img *voidbuffer)
{
	t_engine	*engine;

	engine = get_engine();
	ft_memcpy((*back)->addr, voidbuffer->addr, engine->width * engine->height * 4);
	render_2d(*back);
	swap_buffers(front, back);
	put_frame(*front);
	return (SUCCESS);
}

int	renderer(void)
{
	t_engine *engine;

	engine = get_engine();
	double_buffering(&(engine->renderer->drawbuffer), &(engine->renderer->vbuffer), engine->renderer->voidbuffer);
	return (SUCCESS);
}