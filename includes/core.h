/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:31:24 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/15 11:26:50 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include <errno.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <X11/X.h>
# include <X11/keysym.h>

# include "logging.h"
# include "logic.h"
# include "renderer.h"
# include "object.h"
# include "input.h"

# define FAILURE	-1
# define SUCCESS	0

# define VOID_COLOR	0x0000FF

# define OBJ_2D_MAX	1000

# define PI 		3.14159265359

# define MAX_WIN	10

typedef struct s_win
{
	void			*win_ptr;
	char			*title;
	unsigned int	width;
	unsigned int	height;
	t_mrender		*renderer;
	t_vector2		offset;
}					t_win;

typedef struct s_engine
{
	void			*mlx;
	t_win			win[MAX_WIN];
	int				nb_win;
	int				(*loop_f)(void *);
	t_game_object	*obj2d[OBJ_2D_MAX];
	int				obj2d_count;
	t_debug			*debug[MAX_DEBUG_OBJ];
	int				debug_count;
}			t_engine;

t_engine	*get_engine(void);

int			init_engine(void);

void		loop(int (*f)(void *), void *param);

int			stop_engine(void);

int			__init_renderer(void *mlx_ptr, t_win *win, t_vector2 win_size);

//////////////////////////
//		IO/envent.c		//
//////////////////////////

int			key_hook(int (*f)(), void *param);

int			mouse_hook(int (*f)(), void *param);

int			loop_hook(int (*f)(), void *param);

int			expose_hook(int (*f)(), void *param);

int			event_hook(int (*f)(), int envent, int mask, void *param);

#endif