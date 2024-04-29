/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:00:50 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/29 11:46:19 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORD_H
# define COORD_H

typedef struct s_coord
{
	float	x;
	float	y;
}			t_coord;

t_coord	*new_coord(float x, float y);

void	free_coord(t_coord *coord);

t_coord	*screen_to_world(t_coord *screen);

t_coord	*world_to_screen(t_coord *world);

#endif