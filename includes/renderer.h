/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:04:30 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/28 14:26:54 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include <math.h>
# include <stdlib.h>

# include <vectorft.h>
# include "data.h"

typedef struct s_win		t_win;

typedef struct s_texture	t_texture;

typedef struct s_engine		t_engine;

int			__renderer(void *param);

void		__render_objets(t_engine *engine);

int			create_trgb(unsigned char t, unsigned char r,
				unsigned char g, unsigned char b);

void		__swap_buffers(t_buffer **front, t_buffer **back);

void		__put_frame(t_buffer *frame, void *win);

void		pixel_put(t_win *win, t_vector2 coord, int color);

int			take_pixel(t_texture *texture, t_vector2 coord);

#endif
