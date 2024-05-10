/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:58:08 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/10 15:51:15 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

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

t_game_object	*new_object(unsigned int id);

t_camera		*new_camera(void);

// void		draw_rays(t_object2d *obj, t_vector2 start, t_vector2 end);

#endif