/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:18:56 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/04 11:19:42 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "X11/Xlib.h"
#include "core.h"
#include "mlx_int.h"

void	get_pos_win(int *x, int *y)
{
	t_engine			*engine;
	t_xvar				*xvar;
	XWindowAttributes	win_attr;

	engine = __get_engine();
	xvar = engine->mlx;
	XGetWindowAttributes(xvar->display, xvar->win_list->window, &win_attr);
	*x = win_attr.x;
	*y = win_attr.y - (win_attr.y - 1);
}

void	fix_pointer(int x, int y)
{
	t_engine	*engine;
	t_xvar		*xvar;

	engine = __get_engine();
	xvar = engine->mlx;
	XWarpPointer(xvar->display, None, xvar->win_list->window, 0, 0, 0, 0, x, y);
	XFlush(xvar->display);
}
