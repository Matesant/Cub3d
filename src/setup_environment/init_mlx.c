/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 01:36:16 by matesant          #+#    #+#             */
/*   Updated: 2024/07/12 01:58:51 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_player_configs(t_game_essentials *ptr);

void	ft_init_mlx(t_game_essentials *ptr, char *map)
{
	ptr->mlx = mlx_init(HEIGHT, WIDTH, "eae", true);
	ptr->img = mlx_new_image(ptr->mlx, HEIGHT, WIDTH);
	mlx_image_to_window(ptr->mlx, ptr->img, 0, 0);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	ft_set_game_configs(map, ptr);
}

void	ft_player_configs(t_game_essentials *ptr)
{
	ptr->player = malloc(sizeof(t_player_position));
	ptr->player->x = ft_return_x('P', ptr->map) + ptr->map->block_size / 2;
	ptr->player->y = ft_return_y('P', ptr->map) + ptr->map->block_size / 2;
}
