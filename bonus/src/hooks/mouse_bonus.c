/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:13:55 by matesant          #+#    #+#             */
/*   Updated: 2024/08/01 16:43:12 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_mouse_left(t_game_essentials *game);
void	ft_mouse_right(t_game_essentials *game);

void	mouse_hook(double x, double y, void *param)
{
	static double		last_x;
	int					sens;
	t_game_essentials	*game;

	game = (t_game_essentials *)param;
	(void)y;
	sens = 2;
	if (last_x < x)
	{
		while (sens--)
			ft_mouse_right(game);
		last_x = x;
	}
	else if (last_x > x)
	{
		while (sens--)
			ft_mouse_left(game);
		last_x = x;
	}
}

void	ft_mouse_left(t_game_essentials *game)
{
	game->player->angle -= 0.06;
	if (game->player->angle < 0)
		game->player->angle += 2 * PI;
	game->player->delta_x = cos(game->player->angle) * MOVE_SPEED;
	game->player->delta_y = sin(game->player->angle) * MOVE_SPEED;
}

void	ft_mouse_right(t_game_essentials *game)
{
	game->player->angle += 0.06;
	if (game->player->angle > 2 * PI)
		game->player->angle -= 2 * PI;
	game->player->delta_x = cos(game->player->angle) * MOVE_SPEED;
	game->player->delta_y = sin(game->player->angle) * MOVE_SPEED;
}
