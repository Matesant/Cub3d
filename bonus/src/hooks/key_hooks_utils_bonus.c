/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 03:27:27 by matesant          #+#    #+#             */
/*   Updated: 2024/08/01 16:17:28 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_move_left(t_game_essentials *game)
{
	game->player->angle -= 0.06;
	if (game->player->angle < 0)
		game->player->angle += 2 * PI;
	game->player->delta_x = cos(game->player->angle) * MOVE_SPEED;
	game->player->delta_y = sin(game->player->angle) * MOVE_SPEED;
}

void	ft_move_right(t_game_essentials *game)
{
	game->player->angle += 0.06;
	if (game->player->angle > 2 * PI)
		game->player->angle -= 2 * PI;
	game->player->delta_x = cos(game->player->angle) * MOVE_SPEED;
	game->player->delta_y = sin(game->player->angle) * MOVE_SPEED;
}
