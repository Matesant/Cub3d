/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:39:08 by matesant          #+#    #+#             */
/*   Updated: 2024/07/19 16:28:03 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdbool.h>
#include <stdio.h>

void	ft_draw_background(mlx_image_t *img, int width, int height)
{
	int	x;
	int	y;

	x = 0;
	while (x < width)
	{
		y = 0;
		while (y < height / 2)
		{
			mlx_put_pixel(img, x, y, 0x00CCCCCC);
			y++;
		}
		x++;
	}
	x = 0;
	while (x < width)
	{
		y = height / 2;
		while (y < height)
		{
			mlx_put_pixel(img, x, y, 0x000000FF);
			y++;
		}
		x++;
	}
}

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

void	ft_init_cordinates(t_line *cordinates, int endx, int endy,
		t_player_pos *player)
{
	cordinates->deltax = ft_abs(endx - player->x);
	cordinates->deltay = -ft_abs(endy - player->y);
	cordinates->step_x = ft_compare_number(player->x, endx, 1);
	cordinates->step_y = ft_compare_number(player->y, endy, 1);
	cordinates->error_accumulated = cordinates->deltax + cordinates->deltay;
	cordinates->double_error = 0;
}

void	ft_put_line(mlx_image_t *img, int endx, int endy, t_player_pos *player)
{
	t_line	cordinates;
	int		x_initial;
	int		y_initial;

	ft_init_cordinates(&cordinates, endx, endy, player);
	x_initial = player->x;
	y_initial = player->y;
	while (1)
	{
		if ((x_initial >= 0 && x_initial < WIDTH && y_initial >= 0
				&& y_initial < HEIGHT) && (endx >= 0 && endx < WIDTH
				&& endy >= 0 && endy < HEIGHT))
		{
			mlx_put_pixel(img, x_initial, y_initial, 0xAAAAAAAF);
		}
		if (x_initial == endx && y_initial == endy)
			break ;
		cordinates.double_error = 2 * cordinates.error_accumulated;
		if (cordinates.double_error >= cordinates.deltay)
		{
			cordinates.error_accumulated += cordinates.deltay;
			x_initial += cordinates.step_x;
		}
		if (cordinates.double_error <= cordinates.deltax)
		{
			cordinates.error_accumulated += cordinates.deltax;
			y_initial += cordinates.step_y;
		}
	}
}

void	ft_put_player(mlx_image_t *img, t_player_pos *player)
{
	int	x;
	int	y;

	x = player->x - player->size / 2;
	while (x < player->x + player->size / 2)
	{
		y = player->y - player->size / 2;
		while (y < player->y + player->size / 2)
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
	while (xo < game->map->block_size)
	{
		yo = 0;
		while (yo < game->map->block_size)
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
