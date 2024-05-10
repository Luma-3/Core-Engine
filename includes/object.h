/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:58:08 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/10 16:50:50 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

# include "logic.h"
# include "component.h"
# include "logging.h"

typedef struct s_game_object
{
	int			type;
	int			id;
	t_transform	trans;
	t_render2d	render;
}				t_game_object;

typedef struct s_camera
{
	t_vector2	coord;
	float		angle;
}				t_camera;

typedef struct s_debug
{
	bool		active;
	t_vector2	start;
	t_vector2	end;
	int			color;
	void		(*draw_ray)(void *obj);
}				t_debug;

t_game_object	*new_object(unsigned int id);

t_camera		*new_camera(void);

t_debug			*new_debug(t_vector2 start, t_vector2 end);

void			draw_ray(void *obj);

// void		draw_rays(t_object2d *obj, t_vector2 start, t_vector2 end);

#endif