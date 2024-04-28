/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:00:19 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/28 15:11:49 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_engine.h"

void	pixel_put(t_img *img, t_coord *coord, int color)
{
	int		offset;

	offset = (roundf(coord->y) * img->l_length
			+ roundf(coord->x) * (img->bpp / 8));
	*(unsigned int *)(img->addr + offset) = color;
}
