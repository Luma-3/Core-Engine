/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrender.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:29:25 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/03 15:29:12 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "renderer.h"

static void	copy_void(t_engine *engine)
{
	t_buffer	*b_back;
	t_buffer	*b_void;
	int			i;

	i = 0;
	while (i < engine->nb_win)
	{
		b_back = engine->win[i]->renderer.b_back;
		b_void = engine->win[i]->renderer.b_void;
		ft_memcpy(b_void->addr, b_back->addr,
			engine->win[i]->width * engine->win[i]->height * 4);
		i++;
	}
}

static void	double_buffering(t_engine *engine)
{
	int			i;
	t_buffer	*b_back;
	t_buffer	*b_front;

	i = 0;
	while (i < engine->nb_win)
	{
		b_back = engine->win[i]->renderer.b_back;
		b_front = engine->win[i]->renderer.b_front;
		__swap_buffers(&b_front,
			&b_back);
		__put_frame(b_front, engine->win[i]);
		i++;
	}
}

int	__renderer(void *param)
{
	t_engine	*engine;

	engine = __get_engine();
	copy_void(engine);
	if (engine->render_f)
		engine->render_f(param);
	double_buffering(engine);
	return (SUCCESS);
}
