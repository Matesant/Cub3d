/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 03:25:27 by matesant          #+#    #+#             */
/*   Updated: 2024/07/26 03:32:38 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_w(t_game_essentials *game)
{
	game->player->x += game->player->delta_x;
	game->player->y += game->player->delta_y;
}

void	ft_move_a(t_game_essentials *game)
{
	game->player->x += game->player->delta_y;
	game->player->y -= game->player->delta_x;
}

void	ft_move_s(t_game_essentials *game)
{
	game->player->x -= game->player->delta_x;
	game->player->y -= game->player->delta_y;
}

void	ft_move_d(t_game_essentials *game)
{
	game->player->x -= game->player->delta_y;
	game->player->y += game->player->delta_x;
}
