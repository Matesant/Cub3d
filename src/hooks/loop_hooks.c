/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:37:43 by matesant          #+#    #+#             */
/*   Updated: 2024/07/26 19:23:49 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_hook(void *param)
{
	t_game_essentials	*ptr;

	ptr = (t_game_essentials *)param;
	ft_draw_background(ptr, ptr->img, WIDTH, HEIGHT);
	ft_draw_map(ptr, ptr->map->block_size);
	ft_put_player(ptr->img_map, ptr->player);
	ft_make_game(ptr);
}

void	ft_resize_hook(int width, int height, void *param)
{
	t_game_essentials	*ptr;

	ptr = (t_game_essentials *)param;
	if (ptr->img)
		mlx_delete_image(ptr->mlx, ptr->img);
	ptr->img = mlx_new_image(ptr->mlx, width, height);
	mlx_image_to_window(ptr->mlx, ptr->img, 0, 0);
	ptr->mlx->width = width;
	ptr->mlx->height = height;
}
