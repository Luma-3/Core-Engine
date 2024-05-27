/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:04:30 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/27 18:07:16 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include <math.h>
# include <stdlib.h>

# include <vectorft.h>

typedef struct s_win		t_win;

typedef struct s_texture	t_texture;

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

void		pixel_put(t_win *win, t_vector2 coord, int color);

int			apply_shade(int color, float shade);

int			__renderer(void *param);

int			create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);

void		put_frame(t_buffer *frame, void *win);

void		swap_buffers(t_buffer **front, t_buffer **back);

void		basic_draw2d(void *self);

t_texture	*init_texture(const char *file_name);

void		destroy_texture(t_texture *texture);

void		destroy_renderer(t_mrender *renderer);

#endif
