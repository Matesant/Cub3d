/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:23:25 by matesant          #+#    #+#             */
/*   Updated: 2024/07/12 01:59:46 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_game_essentials	ptr = {0};

	if (ft_pre_verifications(argc, argv))
		return (0);
	ft_init_mlx(&ptr, argv[1]);
	ft_player_configs(&ptr);
	mlx_loop_hook(ptr.mlx, ft_hook, &ptr);
	mlx_key_hook(ptr.mlx, ft_key_hooks, &ptr);
	mlx_resize_hook(ptr.mlx, ft_resize_hook, &ptr);
	mlx_loop(ptr.mlx);
	return (0);
}
