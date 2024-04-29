/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:53:07 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/29 17:56:14 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "core_engine.h"

t_camera    *new_camera(void)
{
    t_camera *camera;
	t_engine *engine;

	engine = get_engine();
    camera = ft_calloc(1, sizeof(t_camera));
	loginfo(__FILE__, __LINE__, "new camera");
	if (!camera)
	{
		logerror(__FILE__, __LINE__, "malloc() failed");
		return (NULL);
	}
	camera->coord = new_coord(0, 0);
	if (!camera->coord)
		return (NULL);
	engine->camera = camera;
    return (camera);    
}