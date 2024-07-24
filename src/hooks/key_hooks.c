/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:36:49 by matesant          #+#    #+#             */
/*   Updated: 2024/07/19 16:57:50 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	is_wall(t_game_essentials *game, int key)
{
	float	delta_x;
	float	delta_y;
	int		mapX;
	int		mapY;

	delta_x = game->player->delta_x;
	delta_y = game->player->delta_y;
	if (key == MLX_KEY_W)
	{
		mapX = (int) (game->player->x + delta_x) / game->map->block_size;
		mapY = (int) (game->player->y + delta_y) / game->map->block_size;
	}
	else
	{
		mapX = (int) (game->player->x - delta_x) / game->map->block_size;
		mapY = (int) (game->player->y - delta_y) / game->map->block_size;		
	}
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
		exit(0);
	}
	if (mlx_is_key_down(ptr->mlx, KEY_W) && !is_wall(ptr, KEY_W))
	{
		ptr->player->x += ptr->player->delta_x;
		ptr->player->y += ptr->player->delta_y;
	}
	if (mlx_is_key_down(ptr->mlx, KEY_S) && !is_wall(ptr, KEY_S))
	{
		ptr->player->x -= ptr->player->delta_x;
		ptr->player->y -= ptr->player->delta_y;
	}
	if (mlx_is_key_down(ptr->mlx, KEY_A))
	{
		ptr->player->angle -= 0.05;
		if (ptr->player->angle < 0)
			ptr->player->angle += 2 * PI;
		ptr->player->delta_x = cos(ptr->player->angle) * MOVE_SPEED;
		ptr->player->delta_y = sin(ptr->player->angle) * MOVE_SPEED;
	}
	if (mlx_is_key_down(ptr->mlx, KEY_D))
	{
		ptr->player->angle += 0.05;
		if (ptr->player->angle > 2 * PI)
			ptr->player->angle -= 2 * PI;
		ptr->player->delta_x = cos(ptr->player->angle) * MOVE_SPEED;
		ptr->player->delta_y = sin(ptr->player->angle) * MOVE_SPEED;
	}
}

void toggle_minimap(mlx_key_data_t keydata, void* param)
{
	t_game_essentials	*game;

	game = (t_game_essentials *) param;
	if (keydata.key == MLX_KEY_TAB && keydata.action == MLX_PRESS)
	{
		if (game->img_map->instances[0].enabled == false)
			game->img_map->instances[0].enabled = true;
		else
			game->img_map->instances[0].enabled = false;
	}
}
