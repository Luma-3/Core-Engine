/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:04:30 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/21 17:01:32 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include <math.h>
# include <stdlib.h>

# include "core.h"
# include "data.h"

void		pixel_put(t_buffer *img, t_vector2 coord, int color);

void		copy_pixel(t_win *win, t_texture *texture,
				t_vector2 coord_dst, t_vector2 coord_src);

int			create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);

int			renderer(void *param);

void		put_frame(t_buffer *frame, void *win);

void		swap_buffers(t_buffer **front, t_buffer **back);

void		basic_draw2d(void *self);

int			update_game(void *obj);

t_texture	*init_texture(const char *file_name);

void		destroy_texture(t_texture *texture);

#endif
