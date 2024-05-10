/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:53:07 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/10 15:22:48 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "core.h"

t_camera	*new_camera(void)
{
	t_camera	*camera;
	t_engine	*engine;

	engine = get_engine();
	camera = ft_calloc(1, sizeof(t_camera));
	loginfo(__FILE__, __LINE__, "new camera");
	if (!camera)
	{
		logerror(__FILE__, __LINE__, "malloc() failed");
		return (NULL);
	}
	camera->coord = vector2(0, 0);
	engine->camera = camera;
	return (camera);
}
