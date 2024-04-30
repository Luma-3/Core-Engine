/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_engine.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:31:24 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/30 14:04:36 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_ENGINE_H
# define CORE_ENGINE_H

# include <errno.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <X11/X.h>
# include <X11/keysym.h>

# include "logging.h"
# include "coord.h"
# include "render.h"
# include "object.h"
# include "key_bind.h"

# define FAILURE -1
# define SUCCESS 0

# define CONFIG_FILE "./config.cfg"

# define VOID_COLOR 0x0000FF

# define OBJ_2D_MAX 300

typedef struct s_engine
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	char		*title;
	t_camera	*camera;
	t_renderer	*renderer;
	t_object2d	*object_2d[OBJ_2D_MAX];
}			t_engine;

t_engine	*get_engine(void);

int			init_engine(void);

void		loop(void);

int			parse_config(t_engine *engine, t_list *config);

int			read_config(t_engine *engine);

int			stop_engine(void);

int			__init_renderer(t_engine *engine);

//////////////////////////
//		IO/envent.c		//
//////////////////////////

int			key_hook(int (*f)(), void *param);

int			mouse_hook(int (*f)(), void *param);

int			loop_hook(int (*f)(), void *param);

int			expose_hook(int (*f)(), void *param);

int			event_hook(int (*f)(), int envent, int mask, void *param);

#endif