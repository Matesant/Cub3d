/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:23:25 by matesant          #+#    #+#             */
/*   Updated: 2024/07/11 19:38:11 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_game_essentials	ptr = {0};

	ptr.mlx = NULL;
	if (ft_pre_verifications(argc, argv))
		return (1);
	ft_set_game_configs(argv[1], &ptr);
	ptr.mlx = mlx_init(HEIGHT, WIDTH, "eae", true);
	ptr.img = mlx_new_image(ptr.mlx, HEIGHT, WIDTH);
	mlx_image_to_window(ptr.mlx, ptr.img, 0, 0);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	ptr.player = malloc(sizeof(t_player_position));
	mlx_loop_hook(ptr.mlx, ft_hook, &ptr);
	mlx_key_hook(ptr.mlx, ft_key_hooks, &ptr);
	mlx_resize_hook(ptr.mlx, ft_resize_hook, &ptr);
	mlx_loop(ptr.mlx);
	mlx_terminate(ptr.mlx);
	return (0);
}
