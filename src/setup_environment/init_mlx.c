/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 01:36:16 by matesant          #+#    #+#             */
/*   Updated: 2024/07/19 16:51:37 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_player_configs(t_game_essentials *ptr);

void	ft_init_mlx(t_game_essentials *ptr)
{
	ptr->mlx = mlx_init(WIDTH, HEIGHT, "eae", true);
	ptr->img = mlx_new_image(ptr->mlx, WIDTH, HEIGHT);
	ptr->img_background = mlx_new_image(ptr->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(ptr->mlx, ptr->img, 0, 0);
	mlx_image_to_window(ptr->mlx, ptr->img_background, 0, 0);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
}

void	ft_player_configs(t_game_essentials *ptr)
{
	ptr->player = malloc(sizeof(t_player_pos));
	ptr->player->size = 16;
	ptr->player->angle = 5.49779;
	ptr->player->x = ft_return_x('N', ptr->map) + ptr->map->block_size / 2;
	ptr->player->y = ft_return_y('N', ptr->map) + ptr->map->block_size / 2;
	ptr->player->delta_x = cos(ptr->player->angle) * 5;
	ptr->player->delta_y = sin(ptr->player->angle) * 5;
}
