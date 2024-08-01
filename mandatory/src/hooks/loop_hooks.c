/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:37:43 by matesant          #+#    #+#             */
/*   Updated: 2024/07/30 14:05:43 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_next_frame(void *param)
{
	t_game_essentials	*game;

	game = (t_game_essentials *)param;
	ft_draw_background(game, game->walls, WIDTH, HEIGHT);
	ft_draw_map(game, game->map->block_size);
	ft_put_player(game->mini_map, game->player);
	ft_ray_cast(game);
}
