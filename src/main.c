/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:23:25 by matesant          #+#    #+#             */
/*   Updated: 2024/07/12 13:29:11 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_game_essentials	game;

	game = (t_game_essentials) {0};
	ft_pre_verifications(argc, argv);
	ft_init_mlx(&game, argv[1]);
	ft_player_configs(&game);
	mlx_loop_hook(game.mlx, ft_hook, &game);
	mlx_key_hook(game.mlx, ft_key_hooks, &game);
	mlx_resize_hook(game.mlx, ft_resize_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
