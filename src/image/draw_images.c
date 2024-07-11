/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:39:08 by matesant          #+#    #+#             */
/*   Updated: 2024/07/11 00:45:58 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_player(mlx_image_t *img, t_player_position *player)
{
	int	x;
	int	y;
	int	player_size;

	player_size = 20;
	x = player->x - player_size;
	while (x <= player->x + player_size)
	{
		y = player->y - player_size;
		while (y <= player->y + player_size)
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
			game->map->draw_block_x = j * block_size;
			game->map->draw_block_y = i * block_size;
			if (game->map->map_matrice[i][j] == '1')
				ft_put_rectangle(game, game->map->draw_block_x,
					game->map->draw_block_y, 0x00FF00FF);
			else if (game->map->map_matrice[i][j] == '0')
				ft_put_rectangle(game, game->map->draw_block_x,
					game->map->draw_block_y, 0x000000FF);
			j++;
		}
		i++;
		game->map->width = ft_strlen(game->map->map_matrice[i]);
	}
}
