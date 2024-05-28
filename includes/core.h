/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:31:24 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/28 13:32:45 by jbrousse         ###   ########.fr       */
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
# include "renderer.h"
# include "object.h"

# define FAILURE	-1
# define SUCCESS	0

# define VOID_COLOR	0x0000FF

# define PI 		3.14159265359

# define MAX_2D_OBJ		1000
# define MAX_DEBUG_OBJ	1000

# define MAX_WIN		10

typedef struct s_win
{
	void			*win_ptr;
	char			*title;
	unsigned int	width;
	unsigned int	height;
	t_mrender		renderer;
	t_vector2		offset;
}					t_win;

typedef struct s_engine
{
	void			*mlx;
	t_win			*win[MAX_WIN];
	int				nb_win;
	int				(*update)(void *);
	void			*update_param;
	void			(*render_f)(void *);
	void			*render_param;
	t_gobject		*obj2d[MAX_2D_OBJ];
	int				obj2d_count;
	t_debug			*debug[MAX_DEBUG_OBJ];
	int				debug_count;
}			t_engine;

t_engine	*__get_engine(void);

int			init_engine(void);

int			init_window(t_vector2 win_size, const char *title);

void		loop(void);

int			__init_renderer(void *mlx_ptr, t_win *win, t_vector2 win_size);

t_vector2	world_to_screen(t_vector2 world, int id_win);

int			stop_engine(void);

void		destroy_texture(t_texture *texture);

void		__destroy_renderer(t_mrender *renderer);

void		destroy_win(t_win *win);

#endif