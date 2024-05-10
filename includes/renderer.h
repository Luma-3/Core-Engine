/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:04:30 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/10 16:50:22 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include <math.h>
# include <stdlib.h>

# include "logic.h"
# include "logging.h"
# include "component.h"
# include "object.h"

# define MAX_2D_OBJ		1000
# define MAX_DEBUG_OBJ	1000

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
	t_render2d	obj2d[MAX_2D_OBJ];
	t_debug		debug[MAX_DEBUG_OBJ];
}				t_mrender;

t_mrender	*get_renderer(void);

void		pixel_put(t_buffer *img, t_vector2 coord, int color);

void		copy_pixel(t_buffer *dst, t_render2d *src,
				t_vector2 dst_c, t_vector2 src_c);

int			create_trgb(int t, int r, int g, int b);

int			init_render2d(t_game_object *obj, size_t width, size_t height);

/**
 * @brief Initialize an image from a xpm file
 * 
 * @param file The path to the xpm file
 * @return t_img* The image structure or NULL if an CRITICAL error occured
*/
int			init_xmp_render2d(t_game_object *obj, const char *file);

int			renderer(void);

void		put_frame(t_buffer *frame);

void		swap_buffers(t_buffer **front, t_buffer **back);

#endif
