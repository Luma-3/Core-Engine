/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:50:19 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/13 14:31:07 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGIC_H
# define LOGIC_H

# include "vectorft.h"

t_vector3	world_to_screen(t_vector3 world);

t_vector2	world_to_screen2d(t_vector2 world);

#endif