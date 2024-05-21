/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:35:30 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/17 18:38:01 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "vectorft.h"
# include "component.h"
# include "object.h"

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
	int				(*loop_f)(void *);
	t_game_object	*obj2d[MAX_2D_OBJ];
	int				obj2d_count;
	t_debug			*debug[MAX_DEBUG_OBJ];
	int				debug_count;
}			t_engine;

#endif