/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:23:25 by matesant          #+#    #+#             */
/*   Updated: 2024/07/30 13:52:03 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game_essentials	game;

	ft_bzero(&game, sizeof(t_game_essentials));
	validade_argv(&game, argc, argv);
	parse(&game, argv[1]);
	ft_init_mlx(&game);
	ft_init_player(&game);
	mlx_loop_hook(game.mlx, render_next_frame, &game);
	mlx_loop_hook(game.mlx, check_movement_keys, &game);
	mlx_key_hook(game.mlx, toggle_minimap, &game);
	mlx_close_hook(game.mlx, close_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
