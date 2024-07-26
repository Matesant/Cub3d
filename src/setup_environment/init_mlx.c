/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 01:36:16 by matesant          #+#    #+#             */
/*   Updated: 2024/07/26 03:59:45 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_mlx(t_game_essentials *ptr)
{
	ptr->mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", false);
	ptr->img = mlx_new_image(ptr->mlx, WIDTH, HEIGHT);
	ptr->img_map = mlx_new_image(ptr->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(ptr->mlx, ptr->img, 0, 0);
	mlx_image_to_window(ptr->mlx, ptr->img_map, 0, 0);
	ptr->img_map->instances[0].z = 2;
}

t_vector	get_start_position(t_game_essentials *game)
{
	char		**matrice;
	int			line;
	int			column;

	matrice = game->map->map_matrice;
	line = -1;
	while (matrice[++line])
	{
		column = -1;
		while (matrice[line][++column])
		{
			if (ft_strchr("NSEW", matrice[line][column]))
				return ((t_vector) {column, line});
		}
	}
	return ((t_vector) {0});
}

float	get_initial_angle(t_game_essentials *game)
{
	float		angle;
	char		**matrice;
	char		c;
	t_vector	start;

	matrice = game->map->map_matrice;
	start = game->player->pos;
	c = matrice[(int) start.y][(int)start.x];
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

void	ft_player_configs(t_game_essentials *ptr)
{
	ptr->player = ft_calloc(1, sizeof(t_player_pos));
	ptr->player->size = 16;
	ptr->player->pos = get_start_position(ptr);
	ptr->player->angle = get_initial_angle(ptr);
	ptr->player->x = ptr->player->pos.x * ptr->map->block_size + ptr->map->block_size / 2;
	ptr->player->y = ptr->player->pos.y * ptr->map->block_size + ptr->map->block_size / 2;
	ptr->player->delta_x = cos(ptr->player->angle) * MOVE_SPEED;
	ptr->player->delta_y = sin(ptr->player->angle) * MOVE_SPEED;
}
