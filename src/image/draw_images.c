/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:39:08 by matesant          #+#    #+#             */
/*   Updated: 2024/07/13 01:14:28 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdbool.h>
#include <stdio.h>

int	ft_return_x(char character, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map_matrice[i][j] == character)
				return (j * map->block_size);
			j++;
		}
		i++;
	}
	return (-1);
}

int	ft_return_y(char character, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map_matrice[i][j] == character)
				return (i * map->block_size);
			j++;
		}
		i++;
	}
	return (-1);
}
void	print_cordinates_sx_xy_err_e2(int x0, int y0, int sx, int sy, int err,
		int e2)
{
	printf("x0: %d\n", x0);
	printf("y0: %d\n", y0);
	printf("sx: %d\n", sx);
	printf("sy: %d\n", sy);
	printf("err: %d\n", err);
	printf("e2: %d\n", e2);
}

void	ft_put_line(mlx_image_t *img, int x0, int y0, int x1, int y1, int color)
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;

	dx = ft_abs(x1 - x0);
	sx = x0 < x1 ? 1 : -1;
	dy = -ft_abs(y1 - y0);
	sy = y0 < y1 ? 1 : -1;
	err = dx + dy;
	while (1)
	{
		mlx_put_pixel(img, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void	ft_put_player(mlx_image_t *img, t_player_position *player)
{
	int	x;
	int	y;
	int	line_x;
	int	line_y;
	int	line_length;

	x = player->x - player->size / 2;
	while (x <= player->x + player->size / 2)
	{
		y = player->y - player->size / 2;
		while (y <= player->y + player->size / 2)
		{
			mlx_put_pixel(img, x, y, 0x00FFAAA0);
			y++;
		}
		x++;
	}
	line_length = 100;
	line_x = player->x + line_length * cos(player->angle);
	line_y = player->y + line_length * sin(player->angle);
	ft_put_line(img, player->x, player->y, line_x, line_y, 0xFF0000FF);
}

void	ft_put_rectangle(t_game_essentials *game, int x, int y, int color)
{
	int	xo;
	int	yo;

	xo = 0;
	while (xo < game->map->block_size - 1)
	{
		yo = 0;
		while (yo < game->map->block_size - 1)
		{
			mlx_put_pixel(game->img, x + xo, y + yo, color);
			yo++;
		}
		xo++;
	}
}

void	ft_draw_map(t_game_essentials *game, int block_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			game->map->block_x = (j * block_size);
			game->map->block_y = (i * block_size);
			if (game->map->map_matrice[i][j] == '1')
				ft_put_rectangle(game, game->map->block_x, game->map->block_y,
					0x00FF00FF);
			else
				ft_put_rectangle(game, game->map->block_x, game->map->block_y,
					0x000000FF);
			j++;
		}
		i++;
	}
}
