/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:39:08 by matesant          #+#    #+#             */
/*   Updated: 2024/07/12 01:22:43 by matesant         ###   ########.fr       */
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

void	ft_put_player(mlx_image_t *img, t_player_position *player, t_map *map)
{
	int	x;
	int	y;
	int	player_size;

	player_size = 16;
	x = player->x - player_size / 2;
	while (x <= player->x + player_size / 2)
	{
		y = player->y - player_size / 2;
		while (y <= player->y + player_size / 2)
		{
			mlx_put_pixel(img, x, y, 0x00FFAAA0);
			y++;
		}
		x++;
	}
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
