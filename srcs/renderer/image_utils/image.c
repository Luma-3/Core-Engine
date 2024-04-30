/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:13:34 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/30 16:30:16 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "core_engine.h"

static void	__get_addr(t_img *img)
{
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->l_length, &img->endian);
	if (!img->addr)
	{
		logwarning(__FILE__, __LINE__, "mlx_get_data_addr() failed");
	}
}

static int	__get_mlx_img(t_img *img, size_t width, size_t height)
{
	img->img = mlx_new_image(get_engine()->mlx, width, height);
	if (!img->img)
	{
		logerror(__FILE__, __LINE__, "mlx_new_image() failed");
		return (FAILURE);
	}
	__get_addr(img);
	return (SUCCESS);
}

t_img	*init_xmp_img(const char *file)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
	{
		logerror(__FILE__, __LINE__, "malloc() failed");
		return (NULL);
	}
	img->img = mlx_xpm_file_to_image(get_engine()->mlx, (char *)file,
			&img->width, &img->height);
	if (!img->img)
	{
		logerror(__FILE__, __LINE__, "mlx_xpm_file_to_image() failed");
		free(img);
		return (NULL);
	}
	__get_addr(img);
	return (img);
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
