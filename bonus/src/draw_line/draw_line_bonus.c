/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:06:15 by almarcos          #+#    #+#             */
/*   Updated: 2024/07/26 19:23:28 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_vertical_line(mlx_image_t *img, t_point start, t_point end);
static void	draw_horizontal_line(mlx_image_t *img, t_point start, t_point end);
static void	draw_line_larger_y_axis(mlx_image_t *img,
				t_line_drawing_data line_data, t_point start, t_point end);
static void	draw_line_larger_x_axis(mlx_image_t *img,
				t_line_drawing_data line_data, t_point start, t_point end);

void	draw_line(mlx_image_t *img, t_point start, t_point end)
{
	t_line_drawing_data	line_data;

	new_line_data(&line_data, start, end);
	if (line_data.dx == 0)
		draw_vertical_line(img, start, end);
	else if (line_data.dy == 0)
		draw_horizontal_line(img, start, end);
	else
	{
		if (line_data.dx >= line_data.dy)
			draw_line_larger_x_axis(img, line_data, start, end);
		else
			draw_line_larger_y_axis(img, line_data, start, end);
	}
}

static void	draw_vertical_line(mlx_image_t *img, t_point start, t_point end)
{
	if (end.y > start.y)
	{
		while ((int)start.y != (int)end.y)
		{
			start.y++;
			put_pixel(img, (int)start.x, (int)start.y, start.color);
		}
	}
	else
	{
		while ((int)start.y != (int)end.y)
		{
			start.y--;
			put_pixel(img, (int)start.x, (int)start.y, start.color);
		}
	}
}

static void	draw_horizontal_line(mlx_image_t *img, t_point start, t_point end)
{
	if (end.x > start.x)
	{
		while ((int)start.x != (int)end.x)
		{
			start.x++;
			put_pixel(img, (int)start.x, (int)start.y, start.color);
		}
	}
	else
	{
		while ((int)start.x != (int)end.x)
		{
			start.x--;
			put_pixel(img, (int)start.x, (int)start.y, start.color);
		}
	}
}

static void	draw_line_larger_x_axis(mlx_image_t *img,
		t_line_drawing_data line_data, t_point start, t_point end)
{
	line_data.control = line_data.dx / 2;
	put_pixel(img, (int)start.x, (int)start.y, (int)start.color);
	while ((int)start.x != (int)end.x)
	{
		start.x += line_data.inc_x;
		line_data.control -= line_data.dy;
		if (line_data.control < 0)
		{
			start.y += line_data.inc_y;
			line_data.control += line_data.dx;
		}
		put_pixel(img, (int)start.x, (int)start.y, start.color);
	}
}

static void	draw_line_larger_y_axis(mlx_image_t *img,
		t_line_drawing_data line_data, t_point start, t_point end)
{
	line_data.control = line_data.dy / 2;
	put_pixel(img, (int)start.x, (int)start.y, start.color);
	while ((int)start.y != (int)end.y)
	{
		start.y += line_data.inc_y;
		line_data.control -= line_data.dx;
		if (line_data.control < 0)
		{
			start.x += line_data.inc_x;
			line_data.control += line_data.dy;
		}
		put_pixel(img, (int)start.x, (int)start.y, start.color);
	}
}
