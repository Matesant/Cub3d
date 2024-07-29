/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:36:49 by matesant          #+#    #+#             */
/*   Updated: 2024/07/26 06:51:00 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_coordinates(t_game_essentials *game, int key, int *mapX,
		int *mapY)
{
	float	delta_x;
	float	delta_y;

	delta_x = game->player->delta_x * 7.2;
	delta_y = game->player->delta_y * 7.2;
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

void	ft_key_hooks(void *param)
{
	t_game_essentials	*ptr;

	ptr = (t_game_essentials *)param;
	if (mlx_is_key_down(ptr->mlx, KEY_ESC))
	{
		mlx_terminate(ptr->mlx);
		clear(ptr);
		exit(EXIT_SUCCESS);
	}
	if (mlx_is_key_down(ptr->mlx, KEY_W) && !is_wall(ptr, KEY_W))
		ft_move_w(ptr);
	if (mlx_is_key_down(ptr->mlx, KEY_S) && !is_wall(ptr, KEY_S))
		ft_move_s(ptr);
	if (mlx_is_key_down(ptr->mlx, KEY_A) && !is_wall(ptr, KEY_A))
		ft_move_a(ptr);
	if (mlx_is_key_down(ptr->mlx, KEY_D) && !is_wall(ptr, KEY_D))
		ft_move_d(ptr);
	if (mlx_is_key_down(ptr->mlx, MLX_KEY_LEFT))
		ft_move_left(ptr);
	if (mlx_is_key_down(ptr->mlx, MLX_KEY_RIGHT))
		ft_move_right(ptr);
}

void	toggle_minimap(mlx_key_data_t keydata, void *param)
{
	t_game_essentials	*game;

	game = (t_game_essentials *)param;
	if (keydata.key == MLX_KEY_TAB && keydata.action == MLX_PRESS)
	{
		if (game->img_map->instances[0].enabled == false)
			game->img_map->instances[0].enabled = true;
		else
			game->img_map->instances[0].enabled = false;
	}
}
