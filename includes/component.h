/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:18:55 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/17 08:13:21 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPONENT_H
# define COMPONENT_H

# include "vectorft.h"

typedef struct s_transform
{
	t_vector2	pos;
	t_vector2	rot;
	t_vector2	scale;
}				t_transform;

typedef struct s_texture
{
	void			*img;
	char			*addr;
	int				bpp;
	int				l_length;
	int				endian;
	t_vector2		size;
}					t_texture;

typedef struct s_render2d
{
	unsigned int	id_win;
	t_texture		*texture;
	t_transform		*trans;
	void			(*draw)(void *obj);
}			t_render2d;

#endif