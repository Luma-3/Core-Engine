/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:18:56 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/03 20:16:00 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "X11/Xlib.h"
#include "core.h"
#include "mlx_int.h"

static void	get_pos_win(t_xvar *xvar, int *x, int *y)
{
	Window				win;
	XWindowAttributes	win_attr;

	XGetWindowAttributes(xvar->display, xvar->win_list->window, &win_attr);
	XTranslateCoordinates(xvar->display, xvar->win_list->window, win_attr.root,
		-win_attr.border_width, -win_attr.border_width, x, y, &win);
}

void	fix_pointer(int x, int y)
{
	t_engine	*engine;
	t_xvar		*xvar;
	int			x_win;
	int			y_win;

	engine = __get_engine();
	xvar = engine->mlx;
	get_pos_win(xvar, &x_win, &y_win);
	XWarpPointer(xvar->display, None, xvar->win_list->window, 0, 0, 0, 0,
		x + x_win + (engine->win[0]->width / 2),
		y + y_win + (engine->win[0]->height / 2));
	XFlush(xvar->display);
}
