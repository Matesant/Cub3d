/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 01:36:16 by matesant          #+#    #+#             */
/*   Updated: 2024/07/26 19:23:59 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_mlx(t_game_essentials *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", false);
	game->walls = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->mini_map = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(game->mlx, game->walls, 0, 0);
	mlx_image_to_window(game->mlx, game->mini_map, 0, 0);
	game->mini_map->enabled = false;
	game->mini_map->instances[0].z = 2;
}

t_vector	get_start_position(t_game_essentials *game)
{
	char	**matrice;
	int		line;
	int		column;

	matrice = game->map->map_matrice;
	line = -1;
	while (matrice[++line])
	{
		column = -1;
		while (matrice[line][++column])
		{
			if (ft_strchr("NSEW", matrice[line][column]))
				return ((t_vector){column, line});
		}
	}
	return ((t_vector){0});
}

float	get_initial_angle(t_game_essentials *game)
{
	float		angle;
	char		**matrice;
	char		c;
	t_vector	start;

	matrice = game->map->map_matrice;
	start = game->player->pos;
	c = matrice[(int)start.y][(int)start.x];
	angle = 0;
	if (c == 'E')
		angle = 0;
	else if (c == 'N')
		angle = M_PI_2 * -1;
	else if (c == 'W')
		angle = (M_PI_2 * 2) * -1;
	else if (c == 'S')
		angle = (M_PI_2 * 3) * -1;
	return (angle);
}

void	ft_init_player(t_game_essentials *game)
{
	game->player = ft_calloc(1, sizeof(t_player_pos));
	game->player->size = 16;
	game->player->pos = get_start_position(game);
	game->player->angle = get_initial_angle(game);
	game->player->x = game->player->pos.x * game->map->block_size
		+ game->map->block_size / 2;
	game->player->y = game->player->pos.y * game->map->block_size
		+ game->map->block_size / 2;
	game->player->delta_x = cos(game->player->angle) * MOVE_SPEED;
	game->player->delta_y = sin(game->player->angle) * MOVE_SPEED;
}
