/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:58:08 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/10 12:31:21 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "coord.h"
# include "logging.h"
# include "render.h"

typedef struct s_game_object
{
	char		*name;
	int			id;
	t_vector3	coord;
	t_vector3	rotation;
	t_vector3	scale;
	t_render2d	render;
}				t_game_object;

typedef struct s_object2d
{
	char				*name;
	int					id;
	t_vector2			coord;
	unsigned int		layer;
	float				scale;
	float				angle;
	t_render2d			render;
	t_vector2			d_point_start;
	t_vector2			d_point_end;
}				t_object2d;

typedef struct s_camera
{
	t_vector2	coord;
	float		angle;
}				t_camera;

t_object2d	*new_obj2d(char *name, unsigned int id);

t_camera	*new_camera(void);

void		draw_rays(t_object2d *obj, t_vector2 start, t_vector2 end);

#endif