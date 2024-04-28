/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:47:13 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/28 18:13:45 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core_engine.h>

int	main(void)
{
	t_object	*object;

	object = new_obj("test", 1);
	if (init_core() == FAILURE)
		return (FAILURE);
	if (init_renderer() == FAILURE)
		return (FAILURE);
	event_hook(stop_engine, 17, 1L << 17, NULL);
	event_hook(stop_engine, 2, 1L << 0, NULL);
	loop();
	return (0);
}
