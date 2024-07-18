/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:36:49 by matesant          #+#    #+#             */
/*   Updated: 2024/07/17 20:43:44 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_key_hooks(mlx_key_data_t key, void *param)
{
	t_game_essentials	*ptr;

	ptr = (t_game_essentials *)param;
	if (key.key == KEY_ESC)
	{
		mlx_terminate(ptr->mlx);
		exit(0);
	}
	if (key.key == KEY_W)
	{
		ptr->player->x += ptr->player->delta_x;
		ptr->player->y += ptr->player->delta_y;
	}
	if (key.key == KEY_S)
	{
		ptr->player->x -= ptr->player->delta_x;
		ptr->player->y -= ptr->player->delta_y;
	}
	if (key.key == KEY_A)
	{
		ptr->player->angle -= 0.1;
		if (ptr->player->angle < 0)
			ptr->player->angle += 2 * PI;
		ptr->player->delta_x = cos(ptr->player->angle) * 5;
		ptr->player->delta_y = sin(ptr->player->angle) * 5;
	}
	if (key.key == KEY_D)
	{
		ptr->player->angle += 0.1;
		if (ptr->player->angle > 2 * PI)
			ptr->player->angle -= 2 * PI;
		ptr->player->delta_x = cos(ptr->player->angle) * 5;
		ptr->player->delta_y = sin(ptr->player->angle) * 5;
	}
}
