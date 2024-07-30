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
	t_game_essentials	ptr;

	ft_bzero(&ptr, sizeof(t_game_essentials));
	ft_pre_verifications(&ptr, argc, argv);
	parse(&ptr, argv[1]);
	ft_init_mlx(&ptr);
	ft_player_configs(&ptr);
	mlx_loop_hook(ptr.mlx, ft_hook, &ptr);
	mlx_loop_hook(ptr.mlx, ft_key_hooks, &ptr);
	mlx_key_hook(ptr.mlx, toggle_minimap, &ptr);
	mlx_close_hook(ptr.mlx, close_hook, &ptr);
	mlx_loop(ptr.mlx);
	return (0);
}
