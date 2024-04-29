/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:04:30 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/29 14:21:34 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "coord.h"
# include "logging.h"
# include <math.h>
# include <stdlib.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_renderer
{
	t_img	*vbuffer;
	t_img	*drawbuffer;
	t_img	*voidbuffer;
}	t_renderer;

void	pixel_put(t_img *img, t_coord *coord, int color);

void	copy_pixel(t_img *dst, t_img *src, t_coord *dst_c, t_coord *src_c);

int		create_trgb(int t, int r, int g, int b);

int		init_renderer(void);

t_img	*init_img(size_t width, size_t height);

int	renderer(void);

void	render_2d(t_img *buffer);

void	put_frame(t_img *frame);

#endif
