/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:09:45 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/21 13:54:51 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t color)
{
	if (x <= 0 || x >= img->width || y <= 0 || y >= img->height)
		return ;
	mlx_put_pixel(img, x, y, color);
}

void	new_line_data(t_line_drawing_data *line_data, t_point start,
		t_point end)
{
	line_data->dx = abs((int) (end.x - start.x));
	line_data->dy = abs((int) (end.y - start.y));
	line_data->control = 0;
	if (end.x > start.x)
		line_data->inc_x = 1;
	else
		line_data->inc_x = -1;
	if (end.y > start.y)
		line_data->inc_y = 1;
	else
		line_data->inc_y = -1;
}
