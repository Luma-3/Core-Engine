/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:58:08 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/29 17:59:47 by jbrousse         ###   ########.fr       */
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

typedef struct s_object2d
{
	char					*name;
	int						id;
	t_coord					*coord;
	unsigned int			layer;
	t_img					*img;

}				t_object2d;

typedef struct s_camera
{
	t_coord		*coord;
}				t_camera;

t_object2d	*new_obj2d(char *name, unsigned int id);

t_camera    *new_camera(void);

#endif