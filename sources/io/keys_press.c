/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_press.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:32:21 by antgabri          #+#    #+#             */
/*   Updated: 2024/05/16 12:54:50 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int	key_press(int keycode, t_keys *keys)
{
	if (keycode == KEY_UP || keycode == KEY_W)
		keys->up = 1;
	if (keycode == KEY_DOWN || keycode == KEY_S)
		keys->down = 1;
	if (keycode == KEY_RIGHT)
		keys->right = 1;
	if (keycode == KEY_LEFT)
		keys->left = 1;
	if (keycode == KEY_A)
		keys->rotate_left = 1;
	if (keycode == KEY_D)
		keys->rotate_right = 1;
	if (keycode == KEY_SHIFT)
		keys->shift = 1;
	return (0);
}

int	key_release(int keycode, t_keys *keys)
{
	if (keycode == KEY_UP || keycode == KEY_W)
		keys->up = 0;
	if (keycode == KEY_DOWN || keycode == KEY_S)
		keys->down = 0;
	if (keycode == KEY_RIGHT)
		keys->right = 0;
	if (keycode == KEY_LEFT)
		keys->left = 0;
	if (keycode == KEY_A)
		keys->rotate_left = 0;
	if (keycode == KEY_D)
		keys->rotate_right = 0;
	if (keycode == KEY_SHIFT)
		keys->shift = 0;
	return (0);
}
