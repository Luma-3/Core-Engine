/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:04:30 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/28 17:04:12 by jbrousse         ###   ########.fr       */
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

int		init_renderer(void);

t_img	*init_img(size_t width, size_t height);

#endif
