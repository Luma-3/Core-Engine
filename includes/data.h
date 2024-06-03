/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:21:46 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/03 20:15:18 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <vectorft.h>
# include <stdbool.h>
# include <X11/X.h>

# define MAX_2D_OBJ		1000
# define MAX_DEBUG_OBJ	1000

# define MAX_WIN		10

typedef struct s_buffer
{
	void		*img;
	char		*addr;
	int			bpp;
	int			l_length;
	int			endian;
	t_vector2	size;
}				t_buffer;

typedef struct s_main_render
{
	t_buffer	*b_front;
	t_buffer	*b_back;
	t_buffer	*b_void;
}				t_mrender;

typedef struct s_transform
{
	t_vector2	pos;
	t_vector2	rot;
	t_vector2	scale;
}				t_transform;

typedef struct s_texture
{
	void			*img;
	char			*addr;
	int				bpp;
	int				l_length;
	int				endian;
	t_vector2		size;
}					t_texture;

typedef struct s_render2d
{
	unsigned int	id_win;
	t_texture		*texture;
	t_transform		*trans;
	void			(*draw)(void *obj);
}			t_render2d;

typedef struct s_gobject
{
	int			type;
	int			id;
	t_transform	trans;
	t_render2d	render;
}				t_gobject;

typedef struct s_debug
{
	bool		active;
	t_vector2	start;
	t_vector2	end;
	int			color;
	int			id_win;
	void		(*draw_ray)(void *obj);
}				t_debug;

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
	int				(*render_f)(void *);
	void			*render_param;
	t_gobject		*obj2d[MAX_2D_OBJ];
	int				obj2d_count;
	t_debug			*debug[MAX_DEBUG_OBJ];
	int				debug_count;
}			t_engine;

#endif