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

void	ft_hook(void *param)
{
	t_game_essentials	*ptr;

	ptr = (t_game_essentials *)param;
	ft_draw_background(ptr, ptr->walls, WIDTH, HEIGHT);
	ft_draw_map(ptr, ptr->map->block_size);
	ft_put_player(ptr->mini_map, ptr->player);
	ft_make_game(ptr);
}

void	ft_resize_hook(int width, int height, void *param)
{
	t_game_essentials	*ptr;

	ptr = (t_game_essentials *)param;
	if (ptr->walls)
		mlx_delete_image(ptr->mlx, ptr->walls);
	ptr->walls = mlx_new_image(ptr->mlx, width, height);
	mlx_image_to_window(ptr->mlx, ptr->walls, 0, 0);
	ptr->mlx->width = width;
	ptr->mlx->height = height;
}
