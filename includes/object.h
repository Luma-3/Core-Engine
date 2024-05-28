/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:58:08 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/28 14:30:13 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

# include "logging.h"
# include "data.h"

t_gobject		*new_object(unsigned int id, t_texture *texture,
					unsigned int win_id);

void			destroy_object(t_gobject *object, int do_destroy_texture);

t_debug			*new_debug(t_vector2 start, t_vector2 end, int id);

void			draw_ray(void *obj);

#endif