/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:58:08 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/27 17:48:57 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

# include "component.h"
# include "logging.h"

typedef struct s_gobject
{
	int			type;
	int			id;
	t_transform	trans;
	t_render2d	render;
}				t_gobject;

typedef struct s_debug
{
	bool		active;
	t_vector2	start;
	t_vector2	end;
	int			color;
	int			id_win;
	void		(*draw_ray)(void *obj);
}				t_debug;

t_gobject		*new_object(unsigned int id, t_texture *texture,
					unsigned int win_id);

void			destroy_object(t_gobject *object, int do_destroy_texture);

t_debug			*new_debug(t_vector2 start, t_vector2 end, int id);

void			draw_ray(void *obj);

#endif