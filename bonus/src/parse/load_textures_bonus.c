/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:08:51 by matesant          #+#    #+#             */
/*   Updated: 2024/08/01 16:18:11 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	load_textures(t_game_essentials *game)
{
	int	i;

	game->textures[NORTH] = mlx_load_png(game->map->texture_path_no);
	game->textures[SOUTH] = mlx_load_png(game->map->texture_path_so);
	game->textures[WEST] = mlx_load_png(game->map->texture_path_we);
	game->textures[EAST] = mlx_load_png(game->map->texture_path_ea);
	i = -1;
	while (++i < 4)
	{
		if (!game->textures[i])
			error(game, "Texture not found or without read permission\n");
	}
}
