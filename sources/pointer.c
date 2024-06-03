/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:18:56 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/03 16:55:22 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "X11/Xlib.h"
#include "mlx_int.h"

void	fix_pointer(int x, int y)
{
	t_engine			*engine;
	t_xvar				*xvar;
	Window				win;
	XWindowAttributes	win_attr;

	engine = __get_engine();
	xvar = engine->mlx;
	XGetWindowAttributes(xvar->display, xvar->win_list->window, &win_attr);
	XTranslateCoordinates(xvar->display, xvar->win_list->window, win_attr.root, -win_attr.border_width, -win_attr.border_width, &x, &y, &win);
	XWarpPointer(xvar->display, None, xvar->win_list->window, 0, 0, 0, 0, x + (engine->win[0]->width / 2), y + (engine->win[0]->height / 2));
	XFlush(xvar->display);
}
