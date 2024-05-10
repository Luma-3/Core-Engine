/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:31:24 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/10 15:21:49 by jbrousse         ###   ########.fr       */
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

# define FAILURE -1
# define SUCCESS 0

# define CONFIG_FILE "./config.cfg"

# define VOID_COLOR 0x0000FF

# define OBJ_2D_MAX 500

# define PI 3.14159265359

typedef struct s_engine
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	char		*title;
	t_keys		keys;
	t_camera	*camera;
	t_mrender	*renderer;
	int			(*loop_f)(void *);
}			t_engine;

t_engine	*get_engine(void);

int			init_engine(void);

void		loop(int (*f)(void *), void *param);

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