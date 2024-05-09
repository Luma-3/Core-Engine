/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bind.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:01:48 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/09 14:41:42 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_BIND_H
# define KEY_BIND_H

# include "core_engine.h"

# define KEY_UP 0xff52
# define KEY_DOWN 0xff54
# define KEY_RIGHT 0xff53
# define KEY_LEFT 0xff51

# define KEY_W 0x0077
# define KEY_A 0x0061
# define KEY_S 0x0073
# define KEY_D 0x0064

typedef struct s_keys
{
	int		up;
	int		down;
	int		left;
	int		right;
	int		rotate_left;
	int		rotate_right;
}			t_keys;

int	key_release(int keycode, t_keys *keys);

int	key_press(int keycode, t_keys *keys);

#endif