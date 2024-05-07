/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:00:50 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/07 14:47:40 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORD_H
# define COORD_H

# include "vectorft.h"

t_vector2	new_coord(float x, float y);

t_vector2	screen_to_world(t_vector2 screen);

t_vector2	world_to_screen(t_vector2 world);

#endif