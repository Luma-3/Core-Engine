/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:47:13 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/29 18:44:50 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core_engine.h>
#include <stdio.h>

# include <X11/X.h>
# include <X11/keysym.h>

static int	deplace_camera(int keycode, t_camera *camera)
{
	// printf("keycode: %d\n", keycode);
	if (keycode == KEY_UP)
		camera->coord->y -= 5;
	if (keycode == KEY_DOWN)
		camera->coord->y += 5;
	if (keycode == KEY_LEFT)
		camera->coord->x -= 5;
	if (keycode == KEY_RIGHT)
		camera->coord->x += 5;
}


int	main(void)
{
	t_object2d	*object;
	t_object2d	*object2;
	t_camera	*camera;

	if (init_core() == FAILURE)
		return (FAILURE);
	if (init_renderer() == FAILURE)
		return (FAILURE);
	camera = new_camera();
	object = new_obj2d("test", 0);
	object->img = init_img(50, 50);
	object->coord->x = -224;
	object->coord->y = -200;
	object2 = new_obj2d("test2", 1);
	object2->img = init_img(50, 50);
	object2->coord->x = 210;
	object2->coord->y = -100;
	event_hook(stop_engine, 17, 1L << 17, NULL);
	// event_hook(stop_engine, 2, 1L << 0, NULL);
	mlx_do_key_autorepeaton(get_engine()->mlx);
	event_hook(deplace_camera,	KeyPress, KeyPressMask, camera);
	// key_hook(deplace_camera, camera);
	loop();
	return (0);
}
