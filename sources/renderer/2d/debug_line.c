/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:10:05 by antgabri          #+#    #+#             */
/*   Updated: 2024/05/09 18:17:28 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_engine.h"

void    draw_line(int x1, int y1, int x2, int y2, t_render2d *buffer)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xIncrement = (float)dx / (float)steps;
    float yIncrement = (float)dy / (float)steps;
    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++)
    {
        pixel_put(buffer, (t_vector2){x, y}, 0x00FF00);
        x += xIncrement;
        y += yIncrement;
    }
}

void	draw_rays(t_object2d *obj, t_vector2 start, t_vector2 end)
{
    obj->d_point_start = world_to_screen(start);
    obj->d_point_end = world_to_screen(end);
}

