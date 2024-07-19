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

int	main(void)
{
	// t_game_essentials	game;

	// game = (t_game_essentials) {0};
	// ft_pre_verifications(&game, argc, argv);
	// parse(&game, argv[1]);
	// printf("%s\n", game.map->texture_path_NO);
	// printf("%s\n", game.map->texture_path_SO);
	// printf("%s\n", game.map->texture_path_WE);
	// printf("%s\n", game.map->texture_path_EA);
	// printf("%u\n", game.map->ceiling_color);
	// printf("%u\n", game.map->floor_color);
	// int i = -1;
	// while (game.map->map_matrice[++i])
	// 	printf("%s\n", game.map->map_matrice[i]);
	// printf("%d\n", game.map->width);
	// printf("%d\n", game.map->height);
	// ft_init_mlx(&game, argv[1]);
	// ft_player_configs(&game);
	// mlx_loop_hook(game.mlx, ft_hook, &game);
	// mlx_key_hook(game.mlx, ft_key_hooks, &game);
	// mlx_resize_hook(game.mlx, ft_resize_hook, &game);
	// mlx_loop(game.mlx);
	// clear(&game);

	mlx_t 			*mlx;
	mlx_image_t		*img;
	t_point			start;
	t_point			end;

	mlx = mlx_init(WIDTH, HEIGHT, "oi", false);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, img, 0, 0);

	start = (t_point) {42, 42, 0, 0xffffffff};
	end = (t_point) {100, 100, 0, 0xffffffff};

	draw_line(img, start, end);
	mlx_loop(mlx);
	return (0);
}

