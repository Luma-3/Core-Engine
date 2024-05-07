/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:04:30 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/07 16:17:57 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "coord.h"
# include "logging.h"
# include <math.h>
# include <stdlib.h>

typedef struct s_triangle
{
	t_vector2		coord[3];
}				t_triangle;

typedef struct s_render2d
{
	void		*img;
	t_triangle	triangle[2];
	char		*addr;
	int			bpp;
	int			l_length;
	int			endian;
	t_vector2	size;
}	t_render2d;

typedef struct s_buffers
{
	t_render2d	*vbuffer;
	t_render2d	*drawbuffer;
	t_render2d	*voidbuffer;
}	t_buffers;

int			double_buffering(t_render2d **front, t_render2d **back,
				t_render2d *voidbuffer);

void		pixel_put(t_render2d *img, t_vector2 *coord, int color);

void		copy_pixel(t_render2d *dst, t_render2d *src,
				t_vector2 *dst_c, t_vector2 *src_c);

int			create_trgb(int t, int r, int g, int b);

t_render2d	init_render2d(size_t width, size_t height);

/**
 * @brief Initialize an image from a xpm file
 * 
 * @param file The path to the xpm file
 * @return t_img* The image structure or NULL if an CRITICAL error occured
 * 
 * @warning If get addr failed, the function will log a warning and not 
 * return NULL ! Check by yourself !!
*/
t_render2d	init_xmp_render2d(const char *file);

int			renderer(void);

void		render_2d(t_render2d *buffer);

void		put_frame(t_render2d *frame);

void		__cal_triangle(t_render2d *render, t_vector2 coord, t_vector2 size);

#endif
