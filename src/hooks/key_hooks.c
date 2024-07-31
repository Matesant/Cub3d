/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:36:49 by matesant          #+#    #+#             */
/*   Updated: 2024/07/30 14:27:32 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_coordinates(t_game_essentials *game, int key, int *mapX,
		int *mapY)
{
	float	delta_x;
	float	delta_y;

	delta_x = game->player->delta_x * 4;
	delta_y = game->player->delta_y * 4;
	if (key == MLX_KEY_W)
	{
		*mapX = (int)(game->player->x + delta_x) / game->map->block_size;
		*mapY = (int)(game->player->y + delta_y) / game->map->block_size;
	}
	else if (key == MLX_KEY_S)
	{
		*mapX = (int)(game->player->x - delta_x) / game->map->block_size;
		*mapY = (int)(game->player->y - delta_y) / game->map->block_size;
	}
	else if (key == MLX_KEY_A)
	{
		*mapX = (int)(game->player->x + delta_y) / game->map->block_size;
		*mapY = (int)(game->player->y - delta_x) / game->map->block_size;
	}
	else if (key == MLX_KEY_D)
	{
		*mapX = (int)(game->player->x - delta_y) / game->map->block_size;
		*mapY = (int)(game->player->y + delta_x) / game->map->block_size;
	}
}

t_bool	is_wall(t_game_essentials *game, int key)
{
	int	mapX;
	int	mapY;

	calculate_coordinates(game, key, &mapX, &mapY);
	if (game->map->map_matrice[mapY][mapX] == '1')
		return (TRUE);
	return (FALSE);
}

void	check_movement_keys(void *param)
{
	t_game_essentials	*game;

	game = (t_game_essentials *)param;
	if (mlx_is_key_down(game->mlx, KEY_ESC))
	{
		mlx_terminate(game->mlx);
		clear(game);
		exit(EXIT_SUCCESS);
	}
	if (mlx_is_key_down(game->mlx, KEY_W) && !is_wall(game, KEY_W))
		ft_move_w(game);
	if (mlx_is_key_down(game->mlx, KEY_S) && !is_wall(game, KEY_S))
		ft_move_s(game);
	if (mlx_is_key_down(game->mlx, KEY_A) && !is_wall(game, KEY_A))
		ft_move_a(game);
	if (mlx_is_key_down(game->mlx, KEY_D) && !is_wall(game, KEY_D))
		ft_move_d(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		ft_move_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		ft_move_right(game);
}

void	toggle_minimap(mlx_key_data_t keydata, void *param)
{
	t_game_essentials	*game;

	game = (t_game_essentials *)param;
	if (keydata.key == MLX_KEY_TAB && keydata.action == MLX_PRESS)
	{
		if (game->mini_map->enabled == false)
			game->mini_map->enabled = true;
		else
			game->mini_map->enabled = false;
	}
}

void	close_hook(void *param)
{
	t_game_essentials	*game;

	game = (t_game_essentials *) param;
	clear(game);
	mlx_terminate(game->mlx);
	exit(EXIT_SUCCESS);
}
