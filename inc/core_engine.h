/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_engine.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:31:24 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/28 17:43:02 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_ENGINE_H
# define CORE_ENGINE_H

# include <errno.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# include "logging.h"
# include "coord.h"
# include "render.h"
# include "object.h"

# define FAILURE -1
# define SUCCESS 0

# define CONFIG_FILE "./../config.cfg"

# define VOID_COLOR 0x0000FF

typedef struct s_engine
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	char		*title;
	t_renderer	*renderer;
}			t_engine;

t_engine	*get_engine(void);

int			init_core(void);

void		loop(void);

int			parse_config(t_engine *engine, t_list *config);

int			read_config(t_engine *engine);

int			stop_engine(void);

//////////////////////////
//		IO/envent.c		//
//////////////////////////

int			key_hook(int (*f)(), void *param);

int			mouse_hook(int (*f)(), void *param);

int			loop_hook(int (*f)(), void *param);

int			expose_hook(int (*f)(), void *param);

int			event_hook(int (*f)(), int envent, int mask, void *param);

#endif