/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:01:48 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/16 12:55:15 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# define KEY_UP 0xff52
# define KEY_DOWN 0xff54
# define KEY_RIGHT 0xff53
# define KEY_LEFT 0xff51

# define KEY_W 0x0077
# define KEY_A 0x0061
# define KEY_S 0x0073
# define KEY_D 0x0064

# define KEY_SHIFT 0xffe1

typedef struct s_keys
{
	int		up;
	int		down;
	int		left;
	int		right;
	int		rotate_left;
	int		rotate_right;
	int		shift;
}			t_keys;

int	key_release(int keycode, t_keys *keys);

int	key_press(int keycode, t_keys *keys);

#endif