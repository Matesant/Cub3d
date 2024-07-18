/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:36:49 by matesant          #+#    #+#             */
/*   Updated: 2024/07/18 13:49:39 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_key_hooks(void *param)
{
	t_game_essentials	*ptr;
	float				move_speed;
	float				rot_speed;

	ptr = (t_game_essentials *)param;
	if (mlx_is_key_down(ptr->mlx, KEY_ESC))
	{
		mlx_terminate(ptr->mlx);
		exit(0);
	}
	if (mlx_is_key_down(ptr->mlx, KEY_W))
	{
		ptr->player->x += ptr->player->delta_x;
		ptr->player->y += ptr->player->delta_y;
	}
	if (mlx_is_key_down(ptr->mlx, KEY_S))
	{
		ptr->player->x -= ptr->player->delta_x;
		ptr->player->y -= ptr->player->delta_y;
	}
	if (mlx_is_key_down(ptr->mlx, KEY_A))
	{
		ptr->player->angle -= 0.05;
		if (ptr->player->angle < 0)
			ptr->player->angle += 2 * PI;
		ptr->player->delta_x = cos(ptr->player->angle) * MOVE_SPEED;
		ptr->player->delta_y = sin(ptr->player->angle) * MOVE_SPEED;
	}
	if (mlx_is_key_down(ptr->mlx, KEY_D))
	{
		ptr->player->angle += 0.05;
		if (ptr->player->angle > 2 * PI)
			ptr->player->angle -= 2 * PI;
		ptr->player->delta_x = cos(ptr->player->angle) * MOVE_SPEED;
		ptr->player->delta_y = sin(ptr->player->angle) * MOVE_SPEED;
	}
}
