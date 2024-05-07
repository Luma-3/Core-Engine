/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:29:25 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/07 13:07:03 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_engine.h"
#include "render.h"

int	renderer(void)
{
	t_engine	*engine;

	engine = get_engine();
	double_buffering(&(engine->renderer->drawbuffer),
		&(engine->renderer->vbuffer), engine->renderer->voidbuffer);
	return (SUCCESS);
}
