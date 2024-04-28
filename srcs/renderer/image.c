/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:13:34 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/28 15:24:41 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "core_engine.h"

int	__get_mlx_img(t_img *img, size_t width, size_t height)
{
	img->img = mlx_new_image(get_engine()->mlx, width, height);
	if (!img->img)
	{
		logerror(__FILE__, __LINE__, "mlx_new_image() failed");
		free(img);
		return (FAILURE);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->l_length, &img->endian);
	if (!img->addr)
	{
		logerror(__FILE__, __LINE__, "mlx_get_data_addr() failed");
		mlx_destroy_image(get_engine()->mlx, img->img);
		free(img);
		return (FAILURE);
	}
	return (SUCCESS);
}

t_img	*init_img(size_t width, size_t height)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
	{
		logerror(__FILE__, __LINE__, "malloc() failed");
		return (NULL);
	}
	if (__get_mlx_img(img, width, height) == FAILURE)
	{
		free(img);
		return (NULL);
	}
	img->width = width;
	img->height = height;
	return (img);
}
