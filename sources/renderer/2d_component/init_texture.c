/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:13:34 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/17 09:10:39 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "core.h"

static int	__get_addr(t_texture *texture)
{
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->l_length, &texture->endian);
	if (!texture->addr)
	{
		logwarning(__FILE__, __LINE__, "mlx_get_data_addr() failed");
		return (FAILURE);
	}
	return (SUCCESS);
}

t_texture	*init_texture_xpm(const char *file_name)
{
	t_engine	*engine;
	t_texture	*texture;
	int			width;
	int			height;

	engine = get_engine();
	texture = (t_texture *)ft_calloc(1, sizeof(t_texture));
	if (texture == NULL)
	{
		logerror(__FILE__, __LINE__, "allocation failed...");
		return (NULL);
	}
	texture->img = mlx_xpm_file_to_image(engine->mlx,
			file_name, &width, &height);
	if (texture->img == NULL)
	{
		logerror(__FILE__, __LINE__, "mlx_xpm_file_to_image() failed");
		return (free(texture), NULL);
	}
	texture->size = vector2 (width, height);
	if (__get_addr(texture) == FAILURE)
	{
		return (free(texture->img), free(texture), NULL);
	}
	return (SUCCESS);
}
